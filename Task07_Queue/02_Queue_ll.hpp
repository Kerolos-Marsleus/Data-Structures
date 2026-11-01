#pragma once
#include "01_LC707_Singly_Linked_List.hpp"

class Queue_ll{
    private:
        MyLinkedList ll;

    public:
        void enqueue(int x);
        bool dequeue();
        bool front(int &out)const ;
        bool back(int &out)const ;
        int size()const;
        bool empty()const;
};