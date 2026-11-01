#include <iostream>
#include "01_Stack_Array.hpp"
#include "02_Stack_ll.hpp"

int main(void){
    Stack_array s;
    int x;
    std::cout << s.pop() << s.top(x) << '\n';
    for(int i = 0; i < 50; i++){s.push(i);}
    std::cout << s.push(100) << '\n';
}