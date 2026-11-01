#include <iostream>
#include "Array.hpp"
using namespace std;






int main(){
    Array arr(2);
    arr.Add(1); arr.Add(2); arr.Add(3);   
    arr.Display();                        

    arr.Insert(0, 0);     
    arr.Delete(0);           

    arr.set(1, 9);                        
    cout << arr.get(1) << '\n';           
    cout << arr.Search(3) << '\n';        

    int lo, hi;  double avg;
    arr.min(lo);  arr.max(hi);  arr.Average(avg);
    cout << lo << ' ' << hi << ' ' << arr.sum() << ' ' << avg << '\n';  // 1 9 13 4.33333

    arr.reverse();        
    arr.Display();  
    arr.rotate_left(1);   
    arr.Display();  
    arr.rotate_right(1);  
    arr.Display();  
    arr.shift_right(2);   
    arr.Display();  
    arr.shift_left(2);    
    arr.Display();  

    Array arr2;
    arr2.Add(7); arr2.Add(8);
    arr.Merge(arr2);      
    arr.Display();  

    Array b = arr;
    b.set(0, 99);
    arr.Display();                        
    b.Display();                          

}
