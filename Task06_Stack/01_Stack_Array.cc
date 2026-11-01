#include "01_Stack_Array.hpp"

bool Stack_array::push(int value){
    if(sp == StackCapacity){
        return false;
    }
    data[sp++] = value;
    return true;
}

bool Stack_array::pop(){
    if(sp <= 0){
        return false;
    }
    sp--;
    return true;
}

bool Stack_array::top(int &out) const{
    if(sp <= 0){
        return false;
    }
    out = data[sp-1];
    return true;
}
bool Stack_array::empty() const{
    return sp == 0;  
}
int Stack_array::size() const{
    return sp;
}