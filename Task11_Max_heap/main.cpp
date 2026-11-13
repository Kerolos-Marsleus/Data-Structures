#include <cassert>
#include <iostream>
#include <vector>
#include "01_Max_Heap.hpp"

int main() {
    maxHeap h;
    int x;
    bool ok;

    assert(h.empty());
    assert(h.size() == 0);
    ok = h.top(x);
    assert(!ok);
    ok = h.pop();
    assert(!ok);

    for (int v : {10, 20, 30, 25, 5, 40, 35}) h.insert(v);
    assert(h.size() == 7);
    ok = h.top(x);
    assert(ok && x == 40);

    std::vector<int> out;
    while (h.top(x)) {
        out.push_back(x);
        ok = h.pop();
        assert(ok);
    }
    assert((out == std::vector<int>{40, 35, 30, 25, 20, 10, 5}));
    assert(h.empty());

    ok = h.pop();
    assert(!ok);

    std::cout << "All heap tests passed\n";
}