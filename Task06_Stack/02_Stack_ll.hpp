#pragma once
#include "01_LC707_Singly_Linked_List.hpp"
class Stack_ll{
    private:
        MyLinkedList ll;
    public:
        void push(int value);
        bool pop();
        bool top(int &out) const;
        bool empty() const;
        int size() const;
};