#pragma once

class DoublyLinkedList {
    private:
        struct Node
        {
            Node* prev;
            int val;
            Node* next;
        };
        Node* head;
        Node *tail;
        int size; 
    public:
    DoublyLinkedList();
    ~DoublyLinkedList();
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    int get(int index)const;
    void addAtHead(int val);
    void addAtTail(int val);
    void addAtIndex(int index, int val);
    void deleteAtIndex(int index);
    void display() const;
    bool back(int &out) const;
    void displayBackward() const;
    int count() const;
    long long sum()const;
    int max()const;
    int min()const;


};
