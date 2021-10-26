#include "fabric.h"
#include "conditions.h"
#include <iostream>

int main() {
    Conditions c;
    TreeType tree_t;
    HostType host_t;
    int choice;

    std::cout << "Initial state: " << std::endl;
    std::cout << c.init_state.ToString() << std::endl;
    std::cout << "Target state: " << std::endl;
    std::cout << c.target_state.ToString() << std::endl;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << " 1 - Depth-First Search " << std::endl;
    std::cout << " 2 - Iterative Depth Search " << std::endl;
    std::cout << std::endl;
    std::cout << " Enter selection, 0 to quit: ";
    std::cin >> choice;
    getchar();
    std::cout << std::endl;

    if (choice == 0) return 0;
    if (choice == 1) tree_t = TreeType::Deep;
    if (choice == 2) tree_t = TreeType::Iterative;

    std::cout << "-------------------------------------" << std::endl;
    std::cout << " 1 - Debug Mode " << std::endl;
    std::cout << " 2 - Solution Mode " << std::endl;
    std::cout << std::endl;
    std::cout << " Enter selection, 0 to quit: ";
    std::cin >> choice;
    getchar();
    std::cout << std::endl;

    if (choice == 0) return 0;
    if (choice == 1) host_t = HostType::Debug;
    if (choice == 2) host_t = HostType::Solution;

    auto fabric = TreeFabric(tree_t, host_t);
    auto tree = fabric.BuildTreeObj(c.init_state);
    tree->BuildSolvingTree(c.target_state);
    tree->PrintSolution();

    std::cout << "Press ENTER to exit ..." << std::endl;
    getchar();
    return 0;
}
