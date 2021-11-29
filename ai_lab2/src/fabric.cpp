#include "fabric.h"
#include "deep.h"
#include "iterative.h"
#include "asterisk.h"

TreeFabric::TreeFabric(const TreeType& tree_t, const HostType& host_t) : tree_t_(tree_t), host_t_(host_t) {}

std::unique_ptr<Tree> TreeFabric::BuildTreeObj(const TagState& initial_state) {
    Tree* tree;

    if (tree_t_ == TreeType::Deep) {
        tree = new DeepTree(initial_state);
    }
    if (tree_t_ == TreeType::Iterative) {
        tree = new IterativeTree(initial_state);
    }
    if (tree_t_ == TreeType::AsteriskPlace) {
        tree = new AsteriskTree(initial_state, new NotInPlace());
    }
    if (tree_t_ == TreeType::AsteriskManhattan) {
        tree = new AsteriskTree(initial_state, new Manhattan());
    }

    if (host_t_ == HostType::Debug) {
        tree->SetHost(new DebugHost());

    }
    if (host_t_ == HostType::Solution) {
        tree->SetHost(new SolutionHost());
    }

    return std::unique_ptr<Tree>(tree);
}

