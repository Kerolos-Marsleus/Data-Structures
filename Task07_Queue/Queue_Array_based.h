#ifndef _QUEUE_BASED_ARRAY_H
#define _QUEUE_BASED_ARRAY_H


typedef struct Queue_Array_based
{
    int* array;
    int capacity;
    int front_index;
    int rear_index;
    int count;
}Queue;

Queue* CreateQueue(int Capacity);
void DestroyQueue(Queue* q);
int  isEmpty(const Queue* q);   
int  isFull(Queue* q);          

void enqueue(Queue* q, int data);   
int  dequeue(Queue* q);    

#endif /*_QUEUE_BASED_ARRAY_H*/