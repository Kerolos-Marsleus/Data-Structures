#include "03_Deque_ll.hpp"

void Deque_ll::push_front(int x){
    dl.addAtHead(x);
}
void Deque_ll::push_back(int x){
    dl.addAtTail(x);
}
bool Deque_ll::pop_front(){
    if(dl.count() == 0) return false;
    dl.deleteAtIndex(0);
    return true;
}
bool Deque_ll::pop_back(){
    if(dl.count() == 0) return false;
    dl.deleteAtIndex(dl.count()-1);
    return true;
}
bool Deque_ll::front(int &out) const{
    if(dl.count() == 0) return false;
    out = dl.get(0);
    return true;
}
bool Deque_ll::back(int &out) const{
    if(dl.count() == 0) return false;
    return dl.back(out);
}
int  Deque_ll::size() const{
    return dl.count();
}
bool Deque_ll::empty() const{
    return dl.count() == 0;
}