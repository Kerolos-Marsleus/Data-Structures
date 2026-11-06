#include "01_Binary_Tree_Array.hpp"

static int leftChild(int i)  { return 2 * i + 1; }
static int rightChild(int i) { return 2 * i + 2; }
static int parent(int i)     { return (i - 1) / 2; }

bool Binary_tree_array::insert(int value){
    if(nodeCount == BinaryTreeCapacity){
        return false;
    }
    data[nodeCount++] = value;
    return true;
}

bool Binary_tree_array::empty() const{
    return nodeCount == 0;  
}
int Binary_tree_array::countNodes() const{
    return nodeCount;
}

int Binary_tree_array::countLeaves()const{
    int counter = 0; 
    for(int i = 0; i < nodeCount; i++){
        if(leftChild(i) >= nodeCount){
            // it doesn't have a left child
            counter++;
        }
    }
    return counter;
}

int main(){
    
}