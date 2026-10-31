
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
    MyLinkedList() : head{nullptr},
        tail{nullptr},size{0}{
    
    }
    ~MyLinkedList(){
        Node* cur = head;
        while(cur != nullptr){
            Node* dummy = cur;
            cur = cur->next;
            delete dummy;
            size--;
        }
    }
    MyLinkedList(const MyLinkedList&) = delete;
    MyLinkedList& operator=(const MyLinkedList&) = delete;
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
        Node* newnode = new Node;
        newnode->val = val;
        newnode->next = head;
        head = newnode;
        if(size == 0){
            tail = newnode;
        }
        size++;
    }
    
    void addAtTail(int val) {
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
            Node* newNode = new Node;
            newNode->val = val;
            newNode->next = cur->next;
            cur->next = newNode;
            size++;
        }
    }
    
    void deleteAtIndex(int index) {
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
};

/**
 * Your MyLinkedList object will be instantiated and called as such:
 * MyLinkedList* obj = new MyLinkedList();
 * int param_1 = obj->get(index);
 * obj->addAtHead(val);
 * obj->addAtTail(val);
 * obj->addAtIndex(index,val);
 * obj->deleteAtIndex(index);
 */

 int main(void){

 }