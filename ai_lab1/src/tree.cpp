#include "tree.h"
#include <string>

Tree::Node::Node(const TagState& state) : state_(state) {}

Tree::Node::Node(const TagState& state, Tree::Node* parent) : Node(state) {
    parent_ = parent;
    depth_ = parent->depth_ + 1;
}

Tree::Tree(const TagState& initial_state) {
    root_ = new Node(initial_state);
}

Tree::~Tree() {
    CleanBranchUp(solution_, nullptr);
    while (!stack_.empty()) {
        delete stack_.top();
        stack_.pop();
    }
}

bool Tree::UniqueCheck(const TagState& state) const {
    return std::find(unique_states_.begin(),
                     unique_states_.end(),
                     state
                     ) != unique_states_.end();
}

void Tree::CleanBranchUp(Tree::Node* from, const Tree::Node* to) {
    while (from != to) {
        auto next = from->parent_;
        delete from;
        host_->LogDelete();
        from = next;
    }
}

void Tree::SetHost(Host* host) {
    host_ = host;
}

void Tree::PrintSolution() const {
    if (solution_ == nullptr) {
        return;
    }
    host_->PrintComplexity(solution_->depth_);

    if (solution_->depth_ > kMaxSolutionPath) {
        return;
    }

    auto curr_node = solution_;
    while (curr_node != nullptr) {
        host_->PrintSolutionNode(curr_node->state_, curr_node->depth_);
        curr_node = curr_node->parent_;
    }
}
