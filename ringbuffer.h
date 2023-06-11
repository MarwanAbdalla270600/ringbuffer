#ifndef ringbuffer_H
#define ringbuffer_H

#include <stdbool.h>

typedef struct
{
    int maxsize; 
    int front;   
    int rear;    
    int size;    
    char items[]; //flexible struct array member
} ringbuffer;

ringbuffer *newringbuffer(int size);

int size(ringbuffer *pt);

bool isEmpty(ringbuffer *pt);

bool isFull(ringbuffer *pt);

char front(ringbuffer *pt);

bool enqueue(ringbuffer *pt, char x);

bool dequeue(ringbuffer *pt);

#endif