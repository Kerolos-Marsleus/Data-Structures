#include <iostream>
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
    DoublyLinkedList() : head{nullptr},
        tail{nullptr},size{0}{
    
    }
    ~DoublyLinkedList(){
        Node* cur = head;
        while(cur != nullptr){
            Node* dummy = cur;
            cur = cur->next;
            delete dummy;
            size--;
        }
    }
    DoublyLinkedList(const DoublyLinkedList&) = delete;
    DoublyLinkedList& operator=(const DoublyLinkedList&) = delete;
    int get(int index) {
        if(index >= size || index < 0){
            return -1 ;
        }
        Node* cur = head;
        for(int i = 0; i < index; i++){
            cur = cur->next;
        }
        return cur->val;
    }
    
    void addAtHead(int val) {
        Node* newnode = new Node{nullptr,val,head};
        if(size == 0){
            tail = newnode;
        }else{
            head->prev = newnode;
        }
        head = newnode;
        size++;
    }
    
    void addAtTail(int val) {
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
    
    void addAtIndex(int index, int val) {
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
    
    void deleteAtIndex(int index) {
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

    void display() const {
        Node* cur = head;
        while(cur != nullptr){
            std::cout << cur->val << "<->";
            cur = cur->next;
        }
        std::cout << "nullptr\n";
    }

    void displayBackward() const {
        Node* cur = tail;
        while(cur != nullptr){
            std::cout << cur->val << "<->";
            cur = cur->prev;
        }
        std::cout << "nullptr\n";
    }
};

/**
 * Your DoublyLinkedList object will be instantiated and called as such:
 * DoublyLinkedList* obj = new DoublyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

 int main(void){
    DoublyLinkedList dl;
    dl.addAtHead(2);
    dl.addAtHead(4);
    dl.addAtHead(6);
    dl.display();
 }