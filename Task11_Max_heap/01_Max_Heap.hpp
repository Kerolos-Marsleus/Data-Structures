#pragma once
#include <vector>

class maxHeap{
private:
    std::vector<int> vec;

    static int parent(int i);
    static int left(int i);
    static int right(int i);
    void bubbleUp(int i);
    void bubbleDown(int i);
public:
    void insert(int value);
    bool top(int &out) const;   // false if empty
    bool pop();                 // false if empty
    int  size() const;
    bool empty() const;
};