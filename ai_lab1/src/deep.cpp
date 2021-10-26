#include "deep.h"

DeepTree::DeepTree(const TagState& initial_state) : Tree(initial_state) {}

bool DeepTree::BuildSolvingTree(const TagState &target) {
    stack_.push(root_);
    unique_states_.push_back(root_->state_);

    while (!stack_.empty()) {
        auto curr_node = stack_.top();
        stack_.pop();

        host_->PrintCurrentNode(curr_node->state_, curr_node->depth_);
        host_->LogIteration();

        if (curr_node->state_ == target) {
            host_->PrintSolutionFound(true);
            solution_ = curr_node;
            return true;
        }
        host_->PrintSolutionFound(false);

        bool opened = OpenNode(curr_node);

        if (!stack_.empty()) {
            auto next_node = stack_.top();
            host_->PrintStackState(next_node->state_,
                                   next_node->depth_,
                                   (int)stack_.size());
            host_->Interrupt();
            if (!opened) {
                CleanBranchUp(curr_node, next_node->parent_);
            }
        }
        else {
            host_->PrintStackState(curr_node->state_,
                                   curr_node->depth_,
                                   (int)stack_.size());
            host_->Interrupt();
        }
    }

    unique_states_.clear();

    return false;
}

bool DeepTree::OpenNode(Tree::Node *node) {
    auto result = false;
    auto next_states = node->state_.NextStates();
    for (auto state : next_states) {
        if (!UniqueCheck(state)) {
            host_->PrintNewNode(state);
            auto new_node = new Node(state, node);
            host_->LogNew();
            stack_.push(new_node);
            unique_states_.push_back(state);
            result = true;
        }
        else {
            host_->PrintRepeatedNode(state);
        }
    }

    return result;
}
