#include <iostream>
#include "02_Doubly_Linked_list.hpp"
DoublyLinkedList::DoublyLinkedList() : head{nullptr},
    tail{nullptr},size{0}{

}
DoublyLinkedList::~DoublyLinkedList(){
    Node* cur = head;
    while(cur != nullptr){
        Node* dummy = cur;
        cur = cur->next;
        delete dummy;
        size--;
    }
}

int DoublyLinkedList::get(int index) const{
    if(index >= size || index < 0){
        return -1 ;
    }
    Node* cur = head;
    for(int i = 0; i < index; i++){
        cur = cur->next;
    }
    return cur->val;
}

bool DoublyLinkedList::back(int &out) const{
    if(tail == nullptr){return false;}
    out = tail->val;
    return true;
}

void DoublyLinkedList::addAtHead(int val) {
    Node* newnode = new Node{nullptr,val,head};
    if(size == 0){
        tail = newnode;
    }else{
        head->prev = newnode;
    }
    head = newnode;
    size++;
}

void DoublyLinkedList::addAtTail(int val) {
    Node* newNode = new Node{tail,val,nullptr};
    if(size == 0){
        tail = newNode;
        head = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void DoublyLinkedList::addAtIndex(int index, int val) {
    if(index < 0 || index > size){
        return;
    }else if(index == 0){
        addAtHead(val);
    }else if(index == size){
        addAtTail(val);
    }else{
        Node *cur = head;
        for(int i = 0; i < index-1;i++){
            cur= cur->next;
        }
        Node* newNode = new Node{cur,val,cur->next};
        cur->next->prev = newNode;
        cur->next = newNode;
        size++;
    }
}

void DoublyLinkedList::deleteAtIndex(int index) {
    if(index < 0 || index >= size){
        return;
    }
    // the linked list is not empty now
    Node *dummy;
    if(index == 0){
        dummy = head;
        if(size == 1){
            head = nullptr;
            tail = nullptr;
        }else{
            dummy->next->prev = nullptr;
            head = dummy->next;
        }
        
    }else if(index == size-1){
        dummy = tail;
        dummy->prev->next = nullptr;
        tail = dummy->prev;
    }else{
        Node *cur = head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        dummy = cur;
        cur->prev->next = cur->next;
        cur->next->prev = cur->prev;
    }
    delete dummy;
    dummy = nullptr;
    size--;
}


void DoublyLinkedList::display() const {
    Node* cur = head;
    while(cur != nullptr){
        std::cout << cur->val << "<->";
        cur = cur->next;
    }
    std::cout << "nullptr\n";
}

void DoublyLinkedList::displayBackward() const {
    Node* cur = tail;
    while(cur != nullptr){
        std::cout << cur->val << "<->";
        cur = cur->prev;
    }
    std::cout << "nullptr\n";
}

int DoublyLinkedList::count() const{
    return size;
}



long long DoublyLinkedList::sum() const{
    long long sum = 0;
    Node* cur = head;
    while(cur != nullptr){
        sum += cur->val;
        cur = cur->next;
    }
    return sum;

}

int DoublyLinkedList::max() const{
    // return -1 if the list is empty
    int max;
    Node* cur = head;
    if(head == nullptr){
        return -1;
    }else{
        max = cur->val;
        cur = cur->next;
        while(cur != nullptr){
            if(max < cur->val){
                max = cur->val;
            }
            cur = cur->next;
        }
    }
    return max;
}
int DoublyLinkedList::min() const {
    // return -1 if the list is empty
    int min;
    Node* cur = head;
    if(head == nullptr){
        return -1;
    }else{
        min = cur->val;
        cur = cur->next;
        while(cur != nullptr){
            if(min > cur->val){
                min = cur->val;
            }
            cur = cur->next;
        }
    }
    return min;
}

