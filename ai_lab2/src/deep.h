#ifndef AI_LAB1_DEEP_H
#define AI_LAB1_DEEP_H

#include "tree.h"

class DeepTree : public Tree {
public:
    explicit DeepTree(const TagState& initial_state);
    bool BuildSolvingTree(const TagState& target) override;
protected:
    bool OpenNode(Node* node) override;
};


#endif //AI_LAB1_DEEP_H
