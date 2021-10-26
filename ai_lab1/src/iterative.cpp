#include "iterative.h"

IterativeTree::IterativeTree(const TagState &initial_state) : DeepTree(initial_state) {}

bool IterativeTree::BuildSolvingTree(const TagState &target) {
    constexpr int k_max_depth = 362880;
    for (auto i = 0; i < k_max_depth; ++i) {
        depth_limit_ = i;
        bool built = DeepTree::BuildSolvingTree(target);
        if (built) {
            return true;
        }
    }
    return false;
}

bool IterativeTree::OpenNode(Tree::Node *node) {
    if (node->depth_ >= depth_limit_) {
        return false;
    }

    return DeepTree::OpenNode(node);
}

