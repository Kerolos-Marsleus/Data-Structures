#pragma once
#include "02_Doubly_Linked_list.hpp"

class Deque_ll{
    private:
        DoublyLinkedList dl;
    public:
        void push_front(int x);
        void push_back(int x);
        bool pop_front();
        bool pop_back();
        bool front(int &out) const;
        bool back(int &out) const;
        int  size() const;
        bool empty() const;
};