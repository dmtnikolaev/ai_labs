#ifndef AI_LAB1_ASTERISK_H
#define AI_LAB1_ASTERISK_H

#include "deep.h"
#include "assessment.h"

class AsteriskTree : public DeepTree {
public:
    AsteriskTree(const TagState& initial_state, Assessment* assessment)
        : DeepTree(initial_state), assessment_(assessment) {}
protected:
    bool OpenNode(Node* node) override;
private:
    Assessment* assessment_;
    int PathCost(Node* node, int assmnt_val);
    bool Cmp(const Tree::Node* lhs, const Tree::Node* rhs);
};


#endif //AI_LAB1_ASTERISK_H
