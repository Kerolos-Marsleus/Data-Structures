#include <iostream>
#include "02_Queue_ll.hpp"

int main() {
    Queue_ll q;
    int x;
    std::cout << q.dequeue() << q.front(x) << '\n';          // 00: empty

    q.enqueue(1); q.enqueue(2); q.enqueue(3);
    q.front(x); std::cout << x << ' ';                         // 1 (the oldest)
    q.back(x);  std::cout << x << '\n';                        // 3 (the newest)

    q.dequeue();
    q.front(x); std::cout << x << ' ' << q.size() << '\n';     // 2 2
}