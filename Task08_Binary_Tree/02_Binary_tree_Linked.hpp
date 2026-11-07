#pragma once

class BinaryTree {
private:
    struct Node {
        int data;
        Node* left;
        Node* right;
    };
    Node* root;

    // recursive helpers: each one starts from the node it's given
    void printPreOrder(Node* n) const;
    void printInOrder(Node* n) const;
    int  countNodes(Node* n) const;
    int  countLeaves(Node* n) const;
    void destroy(Node* n);

public:
    BinaryTree();
    ~BinaryTree();
    BinaryTree(const BinaryTree&) = delete;
    BinaryTree& operator=(const BinaryTree&) = delete;

    void buildFromInput();          // BFS, level by level
    void printLevelOrder() const;   // BFS
    void printPreOrder() const;     // DFS: node, left, right
    void printInOrder() const;      // DFS: left, node, right
    int  countNodes() const;
    int  countLeaves() const;
};