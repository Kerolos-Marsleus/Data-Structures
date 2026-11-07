#include <iostream>
#include <queue>
#include "02_Binary_tree_Linked.hpp"

// ---------- private recursive helpers ----------
void BinaryTree::printPreOrder(Node* n) const {
    if(n == nullptr){
        return;
    }
    std::cout << n->data << "  ";
    printPreOrder(n->left);
    printPreOrder(n->right);
}

void BinaryTree::printInOrder(Node* n) const {
    if(n == nullptr){
        return;
    }
    printInOrder(n->left);
    std::cout << n->data << "  ";
    printInOrder(n->right);
}

int BinaryTree::countNodes(Node* n) const {
    if(n == nullptr){
        return 0;
    }else{
        return (1+ countNodes(n->left) + countNodes(n->right));
    }
}

int BinaryTree::countLeaves(Node* n) const {
    if(n == nullptr){
        return 0;
    }else if((n->left == nullptr) && (n->right == nullptr)){
        return 1;
    }else {
        return countLeaves(n->left) + countLeaves(n->right);
    }
}

void BinaryTree::destroy(Node* n) {
    if(n == nullptr)return;
    std::queue<Node*> q;
    q.push(n);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        if(cur->left != nullptr){
            q.push(cur->left);
        }
        if(cur->right != nullptr){
            q.push(cur->right);
        }
        delete cur;
    }
}

// ---------- constructor / destructor ----------
BinaryTree::BinaryTree() : root{nullptr} {
}

BinaryTree::~BinaryTree() {
    destroy(root);
    root = nullptr;
}

// ---------- public API ----------
void BinaryTree::buildFromInput() {
    int value;
    std::cout << "Enter -1 to create an empty tree : ";
    std::cin >> value;
    if (value == -1) return;

    root = new Node{value, nullptr,nullptr};
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();

        std::cout << "left child of " << cur->data << " (-1 for none)";
        std::cin >> value;
        if(value != -1){
            Node* newNode = new Node{value, nullptr,nullptr};
            cur->left = newNode;
            q.push(newNode);
        }
        std::cout << "right child of " << cur->data << " (-1 for none)";
        std::cin >> value;
        if(value != -1){
            Node* newNode = new Node{value, nullptr,nullptr};
            cur->right = newNode;
            q.push(newNode);
        }
    }
}

void BinaryTree::printLevelOrder() const {
    if(root == nullptr)return;
    std::queue<Node*> q;
    q.push(root);
    while(!q.empty()){
        Node* cur = q.front();
        q.pop();
        if(cur->left != nullptr){
            q.push(cur->left);
        }
        if(cur->right != nullptr){
            q.push(cur->right);
        }
        std::cout << cur->data << " ";
    }
    std::cout << std::endl;
}

void BinaryTree::printPreOrder() const {
    printPreOrder(root);
    std::cout << "\n";
}

void BinaryTree::printInOrder() const {
    printInOrder(root);
    std::cout << "\n";
}

int BinaryTree::countNodes() const {
    return countNodes(root);
}

int BinaryTree::countLeaves() const {
    return countLeaves(root);
}