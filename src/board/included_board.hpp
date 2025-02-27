#pragma once
#include "util/uuid.hpp"
#include "nlohmann/json_fwd.hpp"
#include <memory>

namespace horizon {
using json = nlohmann::json;

class IncludedBoard {
public:
    IncludedBoard(const UUID &uu, const json &j);
    IncludedBoard(const UUID &uu, const std::string &p);
    IncludedBoard(const IncludedBoard &other);
    json serialize() const;
    UUID get_uuid() const;
    std::string get_name() const;
    void reload();
    bool is_valid() const;

    UUID uuid;
    std::string project_filename;

    std::unique_ptr<class ProjectPool> pool;
    std::unique_ptr<class Block> block;
    std::unique_ptr<class ViaPadstackProvider> vpp;
    std::unique_ptr<class Board> board;

    ~IncludedBoard();

private:
    IncludedBoard(const UUID &uu, const class Project &prj, const std::string &p);
    void reset();
};
} // namespace horizon
