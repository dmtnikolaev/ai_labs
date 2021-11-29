#ifndef AI_LAB1_ITERATIVE_H
#define AI_LAB1_ITERATIVE_H

#include "deep.h"

class IterativeTree : public DeepTree {
public:
    explicit IterativeTree(const TagState& initial_state);
    bool BuildSolvingTree(const TagState& target) override;

protected:
    int depth_limit_ = 0;
    bool OpenNode(Node* node) override;
};


#endif //AI_LAB1_ITERATIVE_H
