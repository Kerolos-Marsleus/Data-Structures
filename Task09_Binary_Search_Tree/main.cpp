#include "01_Binary_Search_tree.hpp"

#include <cassert>
#include <iostream>
#include <vector>

void testBuildFromPreorder() {
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
}

void testOperations() {
    BST tree;
    bool ok;

    // 1. Empty tree
    assert(tree.isEmpty());
    assert(!tree.contains(10));
    ok = tree.remove(10);
    assert(!ok);

    // 2. Insert
    //          50
    //        /    \
    //      30      70
    //     /  \    /  \
    //   20   40  60   80
    for (int v : {50, 30, 70, 20, 40, 60, 80}) {
        ok = tree.insert(v);
        assert(ok);
    }
    assert((tree.inorder()   == std::vector<int>{20, 30, 40, 50, 60, 70, 80}));
    assert((tree.preorder()  == std::vector<int>{50, 30, 20, 40, 70, 60, 80}));
    assert((tree.postorder() == std::vector<int>{20, 40, 30, 60, 80, 70, 50}));

    // 3. Duplicates and search
    ok = tree.insert(30);
    assert(!ok);
    assert(tree.contains(40));
    assert(!tree.contains(45));

    // 4. Remove a leaf (20)
    ok = tree.remove(20);
    assert(ok);
    assert((tree.preorder() == std::vector<int>{50, 30, 40, 70, 60, 80}));

    // 5. Remove a node with one child (30 now has only 40)
    ok = tree.remove(30);
    assert(ok);
    assert((tree.preorder() == std::vector<int>{50, 40, 70, 60, 80}));

    // 6. Remove a node with two children (the root 50 → its successor 60 takes its place)
    ok = tree.remove(50);
    assert(ok);
    assert((tree.preorder() == std::vector<int>{60, 40, 70, 80}));
    assert((tree.inorder()  == std::vector<int>{40, 60, 70, 80}));

    // 7. Remove a value that isn't there
    ok = tree.remove(999);
    assert(!ok);

    // 8. Clear
    tree.clear();
    assert(tree.isEmpty());
    assert(tree.inorder().empty());
}

int main() {
    testBuildFromPreorder();
    testOperations();
    std::cout << "All BST tests passed!\n";
}