#include "Array.hpp"
using namespace std;

Array::Array(size_t cap) : array(new int[cap]), size(0),capacity(cap){}
Array::~Array(){
    delete[] array;
}

Array::Array(const Array& second_array) : 
    array(new int[second_array.capacity]), size(second_array.size), capacity(second_array.capacity){
        for(size_t i = 0; i < second_array.get_size(); i++){
            array[i] = second_array.array[i];
        }
}

void Array::reverse_range(size_t from, size_t to){
    while(from < to){
        replace(from, to);
        from++;
        to--;
    }
}

size_t Array::get_size() const {
    return size;
}

size_t Array::get_capacity() const {
    return capacity;
}

void Array::Display(){
    for(size_t i = 0; i < size; i++){
        cout << array[i] << endl;
    }
}

void Array::grow(){
    int *temp;
    if(capacity == 0){
        temp = new int[DEFAULT_CAP];
        capacity = DEFAULT_CAP;
    }else{
        temp = new int[capacity * 2];
        capacity *= 2;
    }
    for(size_t i = 0; i < size; i++){
        temp[i] = array[i];
    }
    delete[] array;
    array = temp;
}

void Array::Add(int number){
    if(size >= capacity){
        grow();
    }
    array[size] = number;
    size++;
}

bool Array::Average(double &result)const{
    if(size == 0){
        cout << "there are no elements in the Array" << endl;
        return false;
    }
    result = 0;
    for(size_t i = 0; i < size; i++){
        result += array[i];
    }
    result /= size;
    return true;
}

void Array::Insert(size_t index, int number){
    if(index > size){
        cout << "out of range" << endl;
        return;
    }
    if(size+1 > capacity){
        grow();
    }
    size_t curr = size;
    while(curr > index){
        array[curr] = array[curr-1];
        curr--;
    }
    array[index] = number;
    size++;
}

void Array::Delete(size_t index){
    if(index >= size){
        cout << "out of range" << endl;
        return;
    }
    while(index < size-1){
        array[index] = array[index+1];
        index++;
    }
    size--;
}

int Array::Search(int number){
    for(size_t i = 0; i < size; i++){
        if(array[i] == number){
            return i;
        }
    }
    return -1;
}

int Array::get(size_t index)const{
    if(index >= size){
        cout << "out of range" << endl;
        return -1;
    }
    return array[index];
}

void Array::set(size_t index, int number){
    if(index >= size){
        cout << "out of range" << endl;
        return;
    }
    array[index] = number;
}

bool Array::min(int &result)const {
    if(size == 0){
        cout << "There is no elements in the Array" << endl;
        return false;
    }
    result = array[0];
    for(size_t i = 1; i < size; i++){
        if(result > array[i]){
            result = array[i];
        }
    }
    return true;
}

bool Array::max(int &result)const{
    if(size == 0){
        cout << "There is no elements in the Array" << endl;
        return false;
    }
    result = array[0];
    for(size_t i = 1; i < size; i++){
        if(result < array[i]){
            result = array[i];
        }
    }
    return true;
}

void Array::reverse(){
    int left = 0;
    int right = size-1;
    while(left < right){
        replace(left, right);
        left++;
        right--;
    }
}

void Array::replace(int i, int j){
    int temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

long Array::sum(){
    long sum = 0;
    for(size_t i = 0; i < size; i++){
        sum += array[i];
    }
    return sum;
}

void Array::Merge(const Array & object){
    while(capacity < size + object.get_size()){
        grow();
    }
    for(size_t i = 0; i < object.get_size(); i++){
        array[i+size] = object.get(i);
    }
    size += object.get_size();
}

void Array::shift_left(size_t n){
    size_t i = 0;
    for(i = 0; i + n < size ; i++){
        array[i] = array[i+n];
    }
    while(i < size){
        array[i] = 0;
        i++;
    }

}

void Array::shift_right(size_t n){
    if(n == 0)return;
    while(size+n > capacity){
        grow();
    }
    size_t temp = size-1+n;
    while(temp >= n){
        array[temp] = array[temp-n];
        temp--;
    }
    for(size_t i = 0; i < n; i++){
        array[i] = 0;
    }
    size = size+n;
}

void Array::rotate_left(size_t n){
    if(size == 0){
        cout << "There is no elements in the array" << endl;
        return;
    }
    n = n % size;
    if(n == 0)return;
    reverse_range(0,n-1);
    reverse_range(n,size-1);
    reverse_range(0,size-1);
}

void Array::rotate_right(size_t n){
    if(size == 0){
        cout << "There is no elements in the array" << endl;
        return;
    }
    n = n % size;
    rotate_left(size-n);
}

