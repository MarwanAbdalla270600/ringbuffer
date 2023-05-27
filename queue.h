#ifndef QUEUE_H
#define QUEUE_H

// Data structure to represent a queue
#include <stdbool.h>
typedef struct
{
    int *items;  // array to store queue elements
    int maxsize; // maximum capacity of the queue
    int front;   // front points to the front element in the queue (if any)
    int rear;    // rear points to the last element in the queue
    int size;    // current capacity of the queue
} queue;

queue *newQueue(int size);

int size(queue *pt);

bool isEmpty(queue *pt);

int front(queue *pt);

void enqueue(queue *pt, int x);

void dequeue(queue *pt);


#endif