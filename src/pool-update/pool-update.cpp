#include "pool-update.hpp"
#include "nlohmann/json.hpp"
#include "pool/pool_manager.hpp"
#include "pool_updater.hpp"
#include "pool/pool_info.hpp"
#include "logger/logger.hpp"
#include "util/util.hpp"

namespace horizon {

using json = nlohmann::json;

static void status_cb_nop(PoolUpdateStatus st, const std::string msg, const std::string filename)
{
}

class PoolDependencyNode {
public:
    PoolDependencyNode(const PoolInfo &info);
    const UUID uuid;
    const std::vector<UUID> dependencies;
    unsigned int level = 0;
    unsigned int order = 0;
    bool operator<(const PoolDependencyNode &other) const
    {
        return std::make_pair(level, order) < std::make_pair(other.level, other.order);
    }
};

PoolDependencyNode::PoolDependencyNode(const PoolInfo &info) : uuid(info.uuid), dependencies(info.pools_included)
{
}


class PoolDependencyGraph {
public:
    PoolDependencyGraph(const PoolInfo &p);
    std::vector<UUID> get_sorted();
    const std::set<UUID> &get_not_found() const;
    void dump(const std::string &filename) const;

private:
    void add_pool(const PoolInfo &pool_info);
    std::map<UUID, PoolDependencyNode> nodes;
    const UUID root_uuid;
    void visit(PoolDependencyNode &node, unsigned int level);
    std::set<UUID> not_found;
};

PoolDependencyGraph::PoolDependencyGraph(const PoolInfo &info) : root_uuid(info.uuid)
{
    add_pool(info);
}

void PoolDependencyGraph::add_pool(const PoolInfo &info)
{
    if (nodes.emplace(info.uuid, info).second) {
        for (const auto &dep : info.pools_included) {
            if (auto other_pool = PoolManager::get().get_by_uuid(dep)) {
                add_pool(*other_pool);
            }
        }
    }
}

void PoolDependencyGraph::visit(PoolDependencyNode &node, unsigned int level)
{
    if (level > node.level)
        node.level = level;
    unsigned int order = 0;
    for (const auto &dep : node.dependencies) {
        if (nodes.count(dep)) {
            auto &n = nodes.at(dep);
            n.order = order;
            visit(n, level + 1);
            order++;
        }
        else {
            not_found.insert(dep);
        }
    }
}

std::vector<UUID> PoolDependencyGraph::get_sorted()
{
    visit(nodes.at(root_uuid), 0);
    std::vector<const PoolDependencyNode *> nodes_sorted;
    nodes_sorted.reserve(nodes.size());
    for (const auto &[uu, node] : nodes) {
        nodes_sorted.push_back(&node);
    }
    std::sort(nodes_sorted.begin(), nodes_sorted.end(), [](const auto a, const auto b) { return *b < *a; });
    std::vector<UUID> out;
    out.reserve(nodes_sorted.size());
    for (const auto it : nodes_sorted) {
        out.emplace_back(it->uuid);
    }
    return out;
}

const std::set<UUID> &PoolDependencyGraph::get_not_found() const
{
    return not_found;
}


void PoolDependencyGraph::dump(const std::string &filename) const
{
    auto ofs = make_ofstream(filename);
    ofs << "digraph {\n";
    for (const auto &it : nodes) {
        std::string pool_name;
        if (auto pool = PoolManager::get().get_by_uuid(it.first))
            pool_name = pool->name;
        else
            pool_name = "Not found: " + (std::string)it.first;
        ofs << "\"" << (std::string)it.first << "\" [label=\"" << pool_name << "\"]\n";
    }
    for (const auto &it : nodes) {
        for (const auto &dep : it.second.dependencies) {
            ofs << "\"" << (std::string)it.first << "\" -> \"" << (std::string)dep << "\"\n";
        }
    }
    ofs << "}";
}

void pool_update(const std::string &pool_base_path, pool_update_cb_t status_cb, bool parametric,
                 const std::vector<std::string> &filenames)
{
    if (!status_cb)
        status_cb = &status_cb_nop;
    PoolUpdater updater(pool_base_path, status_cb);

    std::set<UUID> parts_updated;
    if (filenames.size() == 0) {
        const PoolInfo pool_info(pool_base_path);
        PoolDependencyGraph pool_dep_graph(pool_info);
        const auto pools_sorted = pool_dep_graph.get_sorted();
        std::vector<std::string> paths;

        auto &db = updater.get_pool().db;
        db.execute("BEGIN TRANSACTION");
        db.execute("DELETE FROM pools_included");
        unsigned int order = pools_sorted.size();
        for (auto &it : pools_sorted) {
            std::string path;
            if (it == pool_info.uuid) {
                path = pool_base_path;
            }
            else {
                auto inc = PoolManager::get().get_by_uuid(it);
                if (inc)
                    path = inc->base_path;
                else
                    throw std::logic_error("pool " + (std::string)it + " not found");
            }

            paths.push_back(path);
            SQLite::Query q(db, "INSERT INTO pools_included (uuid, level) VALUES (?, ?)");
            q.bind(1, it);
            q.bind(2, --order);
            q.step();
        }
        db.execute("COMMIT");

        for (auto &it : pool_dep_graph.get_not_found()) {
            status_cb(PoolUpdateStatus::FILE_ERROR, pool_base_path, "pool " + (std::string)it + " not found");
        }

        updater.update(paths);
    }
    else {
        updater.update_some(filenames, parts_updated);
    }

    if (parametric) {
        if (filenames.size() == 0) // complete update
            pool_update_parametric(updater.get_pool(), status_cb);
        else if (parts_updated.size())
            pool_update_parametric(updater.get_pool(), status_cb, parts_updated);
    }
    status_cb(PoolUpdateStatus::INFO, "", "Done");
    status_cb(PoolUpdateStatus::DONE, "", "");
}

} // namespace horizon
