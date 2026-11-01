#include "01_LC707_Singly_Linked_List.hpp"
MyLinkedList::MyLinkedList() : head{nullptr},
    tail{nullptr},size{0}{

}
MyLinkedList::~MyLinkedList(){
    Node* cur = head;
    while(cur != nullptr){
        Node* dummy = cur;
        cur = cur->next;
        delete dummy;
        size--;
    }
}
int MyLinkedList::get(int index) const {
    if(index >= size || index < 0){
        return -1 ;
    }
    Node* cur = head;
    for(int i = 0; i < index; i++){
        cur = cur->next;
    }
    return cur->val;
}

bool MyLinkedList::back(int &out) const{
    if(tail == nullptr){return false;}
    out = tail->val;
    return true;
}

void MyLinkedList::addAtHead(int val) {
    Node* newnode = new Node;
    newnode->val = val;
    newnode->next = head;
    head = newnode;
    if(size == 0){
        tail = newnode;
    }
    size++;
}

void MyLinkedList::addAtTail(int val) {
    Node* newNode = new Node;
    newNode->val = val;
    newNode->next = nullptr;
    if(size == 0){
        tail = newNode;
        head = newNode;
    }else{
        tail->next = newNode;
        tail = newNode;
    }
    size++;
}

void MyLinkedList::addAtIndex(int index, int val) {
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
        Node* newNode = new Node;
        newNode->val = val;
        newNode->next = cur->next;
        cur->next = newNode;
        size++;
    }
}

void MyLinkedList::deleteAtIndex(int index) {
    if(index < 0 || index >= size){
        return;
    }
    // the linked list is not empty now
    if(index == 0){
        Node* dummy = head;
        head= dummy->next;
        delete dummy;
        dummy = nullptr;
        if(size == 1){
            // the LL will become empty
            tail = nullptr;
        }
    }else{
        Node *cur = head;
        for(int i = 0; i < index-1; i++){
            cur = cur->next;
        }
        Node* dummy = cur->next;
        cur->next = cur->next->next;
        delete dummy;
        dummy = nullptr;
        if(index == size-1){
            tail = cur;
        }
    }
    size--;
}

int MyLinkedList::count() const{
    return size;
}
bool MyLinkedList::empty() const{
    return size == 0;
}



