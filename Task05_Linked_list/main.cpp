#include "02_Doubly_Linked_list.hpp"

int main(void){
    DoublyLinkedList l;
    l.addAtTail(1); l.addAtTail(2); l.addAtTail(3); l.addAtTail(4);
    l.deleteAtIndex(0);  l.display(); l.displayBackward();   // 2 3 4 / 4 3 2
    l.deleteAtIndex(2);  l.display(); l.displayBackward();   // 2 3   / 3 2
    l.deleteAtIndex(0); l.deleteAtIndex(0);
    l.display(); l.displayBackward();                        // empty
    l.addAtHead(9);      l.display();   
}