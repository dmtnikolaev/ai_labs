#ifndef AI_LAB1_FABRIC_H
#define AI_LAB1_FABRIC_H

#include <memory>
#include "tree.h"

enum class TreeType {
    Deep,
    Iterative,
};

enum class HostType {
    Debug,
    Solution,
};

class TreeFabric {
public:
    explicit TreeFabric(const TreeType& tree_t, const HostType& host_t);
    std::unique_ptr<Tree> BuildTreeObj(const TagState& initial_state);
private:
    TreeType tree_t_;
    HostType host_t_;
};


#endif //AI_LAB1_FABRIC_H
