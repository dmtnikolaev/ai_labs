#ifndef AI_LAB1_TREE_H
#define AI_LAB1_TREE_H

#include <stack>
#include <vector>
#include <string>
#include "tag.h"
#include "host.h"

class Tree {
public:
    virtual ~Tree();
    virtual bool BuildSolvingTree(const TagState& target) = 0;
    void SetHost(Host* host);
    void PrintSolution() const;
protected:
    class Node {
    public:
        explicit Node(const TagState& state);
        Node(const TagState& state, Node* parent);

        TagState state_;
        Node* parent_ = nullptr;
        int depth_ = 0;
        int path_cost_ = 0;
    };

protected:
    explicit Tree(const TagState& initial_state);

    Host* host_ = nullptr;
    Node* root_ = nullptr;
    Node* solution_ = nullptr;
    std::vector<Node*> stack_;
    std::vector<TagState> unique_states_;

    [[nodiscard]] bool UniqueCheck(const TagState& state) const;
    virtual bool OpenNode(Node* node) = 0;
    void CleanBranchUp(Node* from, const Node* to);
};


#endif //AI_LAB1_TREE_H
