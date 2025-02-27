#pragma once
#include "common/common.hpp"
#include "nlohmann/json_fwd.hpp"
#include "util/uuid.hpp"
#include "frame/frame.hpp"
#include "package.hpp"
#include "package/pad.hpp"
#include "decal.hpp"
#include <fstream>
#include <map>
#include <set>
#include <vector>
#include "ipool.hpp"
#include "pool_info.hpp"

#include "util/sqlite.hpp"

namespace horizon {

/**
 * Stores objects (Unit, Entity, Symbol, Part, etc.) from the pool.
 * Objects are lazy-loaded when they're accessed for the first time.
 */
class Pool : public IPool {
public:
    /**
     * Constructs a Pool
     * @param base_path Path to the pool containing the pool.db
     */
    Pool(const std::string &base_path, bool read_only = true);
    const class Unit *get_unit(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    const class Entity *get_entity(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    const class Symbol *get_symbol(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    const class Padstack *get_padstack(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    const class Padstack *get_well_known_padstack(const std::string &name, UUID *pool_uuid_out = nullptr) override;
    const class Package *get_package(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    const class Part *get_part(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    const class Frame *get_frame(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    const class Decal *get_decal(const UUID &uu, UUID *pool_uuid_out = nullptr) override;
    std::set<UUID> get_alternate_packages(const UUID &uu) override;
    std::string get_model_filename(const UUID &pkg_uuid, const UUID &model_uuid) override;

    virtual std::string get_filename(ObjectType type, const UUID &uu, UUID *pool_uuid_out = nullptr);
    const std::string &get_base_path() const override;
    bool check_filename(ObjectType type, const std::string &filename, std::string *error_msg = nullptr) const;

    SQLite::Database &get_db() override
    {
        return db;
    }

    class PoolParametric *get_parametric() override
    {
        return nullptr;
    }

    const PoolInfo &get_pool_info() const override
    {
        return pool_info;
    }

    /**
     * The database connection.
     * You may use it to perform more advanced queries on the pool.
     */
    SQLite::Database db;
    /**
     * Clears all lazy-loaded objects.
     * Doing so will invalidate all references pointers by get_entity and
     * friends.
     */
    void clear() override;
    std::string get_tmp_filename(ObjectType type, const UUID &uu) const;
    static int get_required_schema_version();
    virtual ~Pool();
    static const UUID tmp_pool_uuid;

    std::map<std::string, UUID> get_actually_included_pools(bool include_self) override;

protected:
    const std::string base_path;
    const PoolInfo pool_info;

    std::string get_flat_filename(ObjectType type, const UUID &uu) const;

    std::map<UUID, Unit> units;
    std::map<UUID, Entity> entities;
    std::map<UUID, Symbol> symbols;
    std::map<UUID, Padstack> padstacks;
    std::map<UUID, Package> packages;
    std::map<UUID, Part> parts;
    std::map<UUID, Frame> frames;
    std::map<UUID, Decal> decals;
    std::map<std::pair<ObjectType, UUID>, UUID> pool_uuid_cache;
    void get_pool_uuid(ObjectType type, const UUID &uu, UUID *pool_uuid_out);
};
} // namespace horizon
