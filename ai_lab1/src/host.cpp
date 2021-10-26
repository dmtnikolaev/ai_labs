#include "host.h"

#include <iostream>

void DebugHost::PrintCurrentNode(const TagState& state, int depth) const {
    std::cout << "*** Current Node: ***\n";
    std::cout << "(depth: " << depth << ")\n";
    std::cout << state.ToString() << std::endl;
}

void DebugHost::Interrupt() const {
    getchar();
}

void DebugHost::PrintNewNode(const TagState &state) const {
    std::cout << "Child Node: \n";
    std::cout << state.ToString() << std::endl;
}

void DebugHost::PrintSolutionFound(bool found) const {
    if (found) {
        std::cout << "[it is the target state!]\n" << std::endl;
    }
    else {
        std::cout << "[isn't target]\n" << std::endl;
    }
}

void DebugHost::PrintRepeatedNode(const TagState &state) const {
    std::cout << "Repeated Child Node: \n";
    std::cout << "(will not going to stack) \n";
    std::cout << state.ToString() << std::endl;
}

void DebugHost::PrintStackState(const TagState &top_state, int depth, int stack_size) const {
    if (stack_size == 0) {
        std::cout << "** Now Opening Stack is empty! **\n";
        std::cout << "-------------------------------------------------" << std::endl;
        return;
    }
    std::cout << "Now in Opening Stack: " << stack_size << " nodes.\n";
    std::cout << "Next Node to open: \n";
    std::cout << "(depth: " << depth << ")\n";
    std::cout << top_state.ToString();
    std::cout << "-------------------------------------------------" << std::endl;
}

void SolutionHost::LogIteration() {
    time_compl_++;
}

void SolutionHost::LogNew() {
    curr_mem_++;
    if (curr_mem_ > memory_compl_) {
        memory_compl_ = curr_mem_;
    }
}

void SolutionHost::LogDelete() {
    curr_mem_--;
}

void SolutionHost::PrintSolutionNode(const TagState &state, int depth) const {
    std::cout << "(depth: " << depth << ")\n";
    std::cout << state.ToString() << std::endl;
}

void SolutionHost::PrintComplexity(int depth) const {
    std::cout << "*** Solution was found! ***\n";
    std::cout << "Depth: " << depth << "\n";
    std::cout << "Time complexity: " << time_compl_ << " steps\n";
    std::cout << "Memory complexity: " << memory_compl_ << " memory units\n" << std::endl;

    if (depth > kMaxSolutionPath) {
        std::cout << "[too deep to print solution path]" << std::endl;
    }
}
