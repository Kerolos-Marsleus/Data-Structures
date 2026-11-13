#include "01_Max_Heap.hpp"

int maxHeap::parent(int i){
    return (i-1) / 2;
}

int maxHeap::left(int i){
    return 2 * i + 1;
}

int maxHeap::right(int i){
    return 2 * i + 2;
}


void maxHeap::bubbleDown(int i){
    const int n = vec.size();
    
    while(1){
        int largest = i;
        if(left(i) < n && vec[largest] < vec[left(i)]) largest = left(i);
        if(right(i) < n && vec[largest] < vec[right(i)]) largest = right(i);

        if(largest == i) break;
        std::swap(vec[largest], vec[i]);
        i = largest;
    }
}

void maxHeap::bubbleUp(int i){
    while(1){
        int largest = i;
        if(i > 0 && vec[parent(i)] < vec[i]) largest = parent(i);

        if(largest == i) break;
        std::swap(vec[largest], vec[i]);
        i = largest;
    }
}

void maxHeap::insert(int value){
    vec.push_back(value);
    bubbleUp(static_cast<int>(vec.size() - 1));
}

bool maxHeap::top(int &out) const{
    if(vec.size() != 0) {
        out = vec[0];
        return true;
    }
    return false;
}

bool maxHeap::pop(){
    if(vec.empty())return false;
    
    std::swap(vec[0], vec[vec.size()-1]);
    vec.pop_back();
    bubbleDown(0); 
    return true;

}

int maxHeap::size() const{
    return vec.size();
}

bool maxHeap::empty() const{
    return vec.empty();
}