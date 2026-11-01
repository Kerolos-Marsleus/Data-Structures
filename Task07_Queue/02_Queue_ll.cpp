#include "02_Queue_ll.hpp"



void Queue_ll::enqueue(int x){
    ll.addAtTail(x);
}
bool Queue_ll::dequeue(){
    if(ll.empty()){return false;}
    ll.deleteAtIndex(0);
    return true;
}
bool Queue_ll::front(int &out)const {
    if(ll.empty()){return false;}
    out = ll.get(0);
    return true;
}
bool Queue_ll::back(int &out)const {
    return ll.back(out);
}
int Queue_ll::size()const{
    return ll.count();
}
bool Queue_ll::empty()const{
    return ll.empty();
}