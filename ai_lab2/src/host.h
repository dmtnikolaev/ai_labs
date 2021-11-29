#ifndef AI_LAB1_HOST_H
#define AI_LAB1_HOST_H

#include "tag.h"

constexpr static int kMaxSolutionPath = 100;

class Host {
public:
    virtual ~Host() = default;
    virtual void Interrupt() const {};
    virtual void PrintNewNode(const TagState& state) const {};
    virtual void PrintRepeatedNode(const TagState& state) const {};
    virtual void PrintStackState(const TagState& top_state, int depth, int stack_size) const {};
    virtual void PrintCurrentNode(const TagState& state, int depth) const {};
    virtual void PrintSolutionFound(bool found) const {};
    virtual void LogIteration() {};
    virtual void LogNew() {};
    virtual void LogDelete() {};
    virtual void PrintSolutionNode(const TagState& state, int depth) const {};
    virtual void PrintComplexity(int depth) const {};
    virtual void PrintPathCost(int path_cost) const {};
protected:
    Host() = default;
};

class DebugHost : public Host {
public:
    void Interrupt() const override;
    void PrintCurrentNode(const TagState& state, int depth) const override;
    void PrintNewNode(const TagState& state) const override;
    void PrintSolutionFound(bool found) const override;
    void PrintRepeatedNode(const TagState& state) const override;
    void PrintStackState(const TagState& top_state, int depth, int stack_size) const override;
    void PrintPathCost(int path_cost) const override;
};

class SolutionHost : public Host {
public:
    void PrintSolutionNode(const TagState& state, int depth) const override;
    void PrintComplexity(int depth) const override;
    void LogIteration() override;
    void LogNew() override;
    void LogDelete() override;
private:
    int time_compl_ = 0;
    int memory_compl_ = 1;
    int curr_mem_ = 1;
};


#endif //AI_LAB1_HOST_H
