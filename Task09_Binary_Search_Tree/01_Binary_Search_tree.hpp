
#pragma once

#include <memory>
#include <vector>

class BST{
    private:
        
        class Node{
            public:
                int value;
                std::unique_ptr<Node> left;
                std::unique_ptr<Node> right;

                explicit Node(int val) : value{val}{}
        };

        std::unique_ptr<Node> root;
        
        // helper function
        bool insert_helper(std::unique_ptr<Node> & ptr, int value);
        void inorder_helper(const Node *ptr, std::vector<int> &vec)const;
        void preorder_helper(const Node *ptr, std::vector<int> &vec)const;
        void postorder_helper(const Node *ptr, std::vector<int> &vec)const;
        bool remove_helper(std::unique_ptr<Node> & ptr, int value);
        const Node* find_min(const Node *ptr)const;
        const Node* find_max(const Node *ptr)const;
    public:
        BST() = default;
        BST(const BST&) = delete;
        BST& operator=(const BST&) = delete;
        // Returns false when the value already exists.
    bool insert(int val);

    // Returns false when the value is absent.
    bool remove(int val);

    bool contains(int val) const;
    bool isEmpty() const;

    std::vector<int> inorder() const;
    std::vector<int> preorder() const;
    std::vector<int> postorder() const;

    void clear();

    // Accepts valid BST preorder with unique values.
    // Replaces the existing tree.
    void buildFromPreorder(const std::vector<int>& values);
};