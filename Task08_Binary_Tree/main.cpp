#include <iostream>
#include "02_Binary_tree_Linked.hpp"

int main() {
    BinaryTree tree;
    tree.buildFromInput();

    std::cout << "\nPre-order:   ";  tree.printPreOrder();     // 1 2 4 5 3 6 7
    std::cout << "In-order:    ";    tree.printInOrder();      // 4 2 5 1 6 3 7
    // std::cout << "Level-order: "; tree.printLevelOrder();   // 1 2 3 4 5 6 7 (once written)

    std::cout << "Nodes:  " << tree.countNodes()  << '\n';     // 7
    std::cout << "Leaves: " << tree.countLeaves() << '\n';     // 4
}