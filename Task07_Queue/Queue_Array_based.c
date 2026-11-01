#include "Queue_Array_based.h"
#include <stdio.h>
#include <stdlib.h>


Queue* CreateQueue(int Capacity){
    Queue* qptr = (Queue*) malloc(sizeof(Queue));
    if(qptr == NULL)return NULL;
    qptr->array = (int*) malloc(sizeof(int) * Capacity);
    if(qptr->array == NULL){
        free(qptr);
        return NULL;
    }
        qptr->front_index = 0;
    qptr->rear_index = 0;
    qptr->capacity = Capacity;
    return qptr;
}
void DestroyQueue(Queue* q){
    if(q == NULL) return;
    free(q->array);
    free(q);
}

int isEmpty(const Queue *q){
    return (q->front_index == q->rear_index) ;
}



int isFull(Queue* q){
    return (((q->rear_index +1) % (q->capacity)) == q->front_index);
}


void enqueue(Queue* q, int data){
    if(isFull(q)){
        printf("Queue is full\n");
    }else{
        q->rear_index = (q->rear_index +1) % q->capacity;
        q->array[q->rear_index] = data;
    }
}

int dequeue(Queue* q){
    if(isEmpty(q)){
        printf("Queue is empty");
        return -1;
    }

    q->front_index = (q->front_index +1) % q->capacity;
    int value = q->array[q->front_index];
    return value;
}