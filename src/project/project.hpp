#pragma once
#include "util/uuid.hpp"
#include "nlohmann/json_fwd.hpp"
#include <map>
#include <deque>
#include "util/file_version.hpp"

namespace horizon {
using json = nlohmann::json;

class ProjectBlock {
public:
    ProjectBlock(const UUID &uu, const std::string &b, const std::string &s, bool t = false)
        : uuid(uu), block_filename(b), schematic_filename(s), is_top(t)
    {
    }
    UUID uuid;
    std::string block_filename;
    std::string schematic_filename;
    bool is_top;
};

class Project {
private:
    Project(const UUID &uu, const json &, const std::string &base);
    std::string get_filename_rel(const std::string &p) const;

public:
    static Project new_from_file(const std::string &filename);
    static unsigned int get_app_version();
    Project(const UUID &uu);
    ProjectBlock &get_top_block();
    const ProjectBlock &get_top_block() const;

    std::string create(const std::map<std::string, std::string> &meta, const UUID &pool_uuid, const UUID &default_via);

    std::string base_path;
    UUID uuid;
    std::map<UUID, ProjectBlock> blocks;

    std::string vias_directory;
    std::string pictures_directory;
    std::string board_filename;
    std::string pool_directory;

    FileVersion version;

    json serialize() const;

private:
    std::string title_old;
    std::string name_old;

    UUID pool_uuid_old;
    std::string pool_cache_directory_old;
};
} // namespace horizon
