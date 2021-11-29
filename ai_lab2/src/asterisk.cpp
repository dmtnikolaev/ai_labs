#include "asterisk.h"
#include <cmath>
#include <vector>
#include <algorithm>

bool AsteriskTree::OpenNode(Tree::Node *node) {
    auto result = false;
    auto next_states = node->state_.NextStates();
    for (auto state : next_states) {
        host_->PrintNewNode(state);
        auto new_node = new Node(state, node);
        auto path_cost = PathCost(new_node, assessment_->GetEval(new_node->state_));
        new_node->path_cost_ = path_cost;
        host_->PrintPathCost(path_cost);
        host_->LogNew();
        stack_.push_back(new_node);
        result = true;
    }

    std::sort(stack_.begin(), stack_.end(), [this](Node* a, Node* b) {
        return Cmp(a, b);
    });

    return result;
}

int AsteriskTree::PathCost(Tree::Node *node, int assmnt_val) {
    auto f = assmnt_val + node->depth_;

    return std::max(node->parent_->path_cost_, f);
}

bool AsteriskTree::Cmp(const Tree::Node* lhs, const Tree::Node* rhs) {
    return lhs->path_cost_ > rhs->path_cost_;
}
