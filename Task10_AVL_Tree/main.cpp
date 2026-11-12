#include <cassert>
#include <iostream>
#include <vector>
#include "01_AVL_Tree.hpp"


int main(){
    AVL_Tree t;
    bool ok;

    // 1. Empty tree
    assert(t.isEmpty());
    assert(t.height() == 0);
    assert(!t.contains(1));
    ok = t.remove(1);
    assert(!ok);

    // 2. Sorted inserts: a plain BST would become a chain of height 7
    for (int i = 1; i <= 7; ++i) {
        ok = t.insert(i);
        assert(ok);
    }
    assert(!t.isEmpty());
    assert((t.inorder()   == std::vector<int>{1, 2, 3, 4, 5, 6, 7}));
    assert((t.preorder()  == std::vector<int>{4, 2, 1, 3, 6, 5, 7}));   // balanced shape
    assert((t.postorder() == std::vector<int>{1, 3, 2, 5, 7, 6, 4}));
    assert(t.height() == 3);

    // 3. Duplicates and search
    ok = t.insert(5);
    assert(!ok);
    assert(t.contains(5));
    assert(!t.contains(9));

    // 4. Removes without rotation
    ok = t.remove(1);
    assert(ok);
    ok = t.remove(3);
    assert(ok);
    assert((t.inorder()  == std::vector<int>{2, 4, 5, 6, 7}));
    assert((t.preorder() == std::vector<int>{4, 2, 6, 5, 7}));
    assert(t.height() == 3);

    // 5. A remove that forces a rotation (4 becomes right-heavy)
    ok = t.remove(2);
    assert(ok);
    assert((t.inorder()  == std::vector<int>{4, 5, 6, 7}));
    assert((t.preorder() == std::vector<int>{6, 4, 5, 7}));   // 6 is the new root
    assert(t.height() == 3);

    // 6. Removing a value that isn't there
    ok = t.remove(100);
    assert(!ok);

    // 7. Clear
    t.clear();
    assert(t.isEmpty());
    assert(t.height() == 0);
    assert(t.inorder().empty());

    std::cout << "All AVL tests passed\n";
}