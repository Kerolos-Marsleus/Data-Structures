#pragma once
#include <iostream>

class Array{
    private:
        static constexpr size_t DEFAULT_CAP = 4;
        int *array;
        size_t size;
        size_t capacity;
        void reverse_range(size_t from, size_t to);
        void grow();
        
        public:
        Array(size_t cap = DEFAULT_CAP);
        Array(const Array &second_array);
        ~Array();
        size_t get_size()const ;
        size_t get_capacity()const;
        void Display();
        void replace(int i, int j);
        void Add(int number);
        bool Average(double &result)const;
        void Insert(size_t index, int number);
        void Delete(size_t index);
        int Search(int number);
        int get(size_t index) const;
        void set(size_t index, int number);
        bool max(int &result)const ;
        bool min(int &result)const ;
        void reverse();
        long sum();
        void Merge(const Array & object);
        void shift_left(size_t n);
        void shift_right(size_t n);
        void rotate_left(size_t n);
        void rotate_right(size_t n);
    };