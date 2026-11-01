#include "02_Stack_ll.hpp"


void Stack_ll::push(int value){
    ll.addAtHead(value);
}
bool Stack_ll::pop(){
    if(ll.empty()){
        return false;
    }else{
        ll.deleteAtIndex(0);
    }
    return true;
}
bool Stack_ll::top(int &out) const{
    if(ll.empty()){
        return false;
    }
    out = ll.get(0);
    return true;
}
bool Stack_ll::empty() const{
    return ll.empty();
}
int Stack_ll::size() const{
    return ll.count();
}