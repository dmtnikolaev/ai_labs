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

    auto result = false;
    auto next_states = node->state_.NextStates();
    for (auto state : next_states) {
        host_->PrintNewNode(state);
        auto new_node = new Node(state, node);
        host_->LogNew();
        stack_.push_back(new_node);
        result = true;
    }

    return result;

    //return DeepTree::OpenNode(node);
}

