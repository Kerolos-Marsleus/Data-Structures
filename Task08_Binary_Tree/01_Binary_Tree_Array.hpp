#pragma once

class Binary_tree_array{
    private:
        static constexpr int BinaryTreeCapacity = 50;
        int data[BinaryTreeCapacity];
        int nodeCount;

    public:
        Binary_tree_array() : nodeCount{0}{}
        bool insert(int value);
        bool empty() const;
        int countNodes() const;
        int countLeaves()const;
    
    
};