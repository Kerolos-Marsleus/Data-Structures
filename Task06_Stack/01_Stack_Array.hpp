#pragma once


class Stack_array{
    private:
        static constexpr int StackCapacity = 50;
        int data[StackCapacity];
        int sp;

    public:
        Stack_array() : sp{0}{}
        bool push(int value);
        bool pop();
        bool top(int &out) const;
        bool empty() const;
        int size() const;

    
    
};