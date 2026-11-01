#pragma once
class MyLinkedList {
    private:
        struct Node
        {
            int val;
            Node* next;
        };
        Node* head;
        Node *tail;
        int size; 
    public:
    MyLinkedList();
    ~MyLinkedList();
    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList& operator=(const MyLinkedList&) = delete;
    int get(int index) const;
    bool back(int &out) const;
    void addAtTail(int val);
    void addAtHead(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    int count() const;
    bool empty() const;
};

