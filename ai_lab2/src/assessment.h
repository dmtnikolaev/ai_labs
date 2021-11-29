#ifndef AI_LAB1_ASSESSMENT_H
#define AI_LAB1_ASSESSMENT_H

#include "tree.h"
#include "conditions.h"

class Assessment {
public:
    virtual int GetEval(const TagState &state) = 0;
protected:
    Conditions c = {};
    TagState target_ = c.target_state;
};

class NotInPlace : public Assessment {
public:
    int GetEval(const TagState &state) override;
};

class Manhattan : public Assessment {
public:
    int GetEval(const TagState &state) override;
};

#endif //AI_LAB1_ASSESSMENT_H
