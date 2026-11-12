#include "01_Binary_Search_tree.hpp"

#include <cassert>
#include <iostream>
#include <vector>

int main() {
    BST tree;

    const std::vector<std::vector<int>> inputs{
        {},
        {30},
        {30, 40, 50},
        {30, 20, 10},
        {30, 20, 10, 25, 40}
    };

    const std::vector<std::vector<int>> expectedInorder{
        {},
        {30},
        {30, 40, 50},
        {10, 20, 30},
        {10, 20, 25, 30, 40}
    };

    for (std::size_t i = 0; i < inputs.size(); ++i) {
        tree.buildFromPreorder(inputs[i]);

        assert(tree.preorder() == inputs[i]);
        assert(tree.inorder() == expectedInorder[i]);
        assert(tree.isEmpty() == inputs[i].empty());
    }

    // Empty input should also clear an existing tree.
    tree.buildFromPreorder({});
    assert(tree.isEmpty());

    std::cout << "All preorder construction tests passed!\n";
}