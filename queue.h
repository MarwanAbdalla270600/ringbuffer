#ifndef QUEUE_H
#define QUEUE_H

// Data structure to represent a queue
#include <stdbool.h>
#define buffersize 100

typedef struct
{
    int maxsize; // maximum capacity of the queue
    int front;   // front points to the front element in the queue (if any)
    int rear;    // rear points to the last element in the queue
    int size;    // current capacity of the queue
    char items[];  // array to store queue elements
} queue;

queue *newQueue(int size);

int size(queue *pt);

bool isEmpty(queue *pt);

char front(queue *pt);

bool enqueue(queue *pt, char x);

bool dequeue(queue *pt);

void printQueue(queue *pt);

#endif