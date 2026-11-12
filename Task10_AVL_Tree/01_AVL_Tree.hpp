#pragma once

#include <memory>
#include <vector>

class AVL_Tree{
    private:
    class Node{
            public:
                int value;
                int height = 1;
                std::unique_ptr<Node> left;
                std::unique_ptr<Node> right;

                explicit Node(int val) : value{val}{}
        };

        std::unique_ptr<Node> root;
        // private helper functions
        static int getHeight(const Node* node);
        void updateHeight(Node* node);
        int balanceFactor(const Node* node);
        void rotateRight(std::unique_ptr<Node> &node);
        void rotateLeft(std::unique_ptr<Node> &node);
        void reBalance(std::unique_ptr<Node> &node);
        bool insert_helper(std::unique_ptr<Node> & ptr, int value);

        void inorder_helper(const Node *ptr, std::vector<int> &vec)const;
        void preorder_helper(const Node *ptr, std::vector<int> &vec)const;
        void postorder_helper(const Node *ptr, std::vector<int> &vec)const;
        const Node* find_min(const Node *ptr)const;
        const Node* find_max(const Node *ptr)const;
        bool remove_helper(std::unique_ptr<Node> & ptr, int value);


    public:
        AVL_Tree() = default;
        AVL_Tree(const AVL_Tree&) = delete;
        AVL_Tree& operator=(const AVL_Tree&) = delete;
        bool insert(int value);
        void clear();
        bool isEmpty() const;
        std::vector<int> inorder() const;
        std::vector<int> preorder() const;
        std::vector<int> postorder() const;
        bool contains(int val) const;
        int height() const;
        bool remove(int val);

    };