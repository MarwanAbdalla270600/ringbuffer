
#include <stdio.h>
#include <stdlib.h>
#include "ringbuffer.h"

ringbuffer *newringbuffer(int size)
{
    ringbuffer *pt = malloc(sizeof(ringbuffer));
    pt->maxsize = size;
    pt->front = 0;
    pt->rear = -1;
    pt->size = 0;
    return pt;
}

int size(ringbuffer *pt)
{
    return pt->size;
}

bool isEmpty(ringbuffer *pt)
{
    return !size(pt);
}

bool isFull(ringbuffer *pt)
{
    return pt->size == pt->maxsize;
}

char front(ringbuffer *pt)
{
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    return pt->items[pt->front];
}

// Utility function to add an element `x` to the queue
bool enqueue(ringbuffer *pt, char x)
{
    if (size(pt) == pt->maxsize)
    {
        return false;
    }

    printf("Inserting %c\t", x);

    pt->rear = (pt->rear + 1) % pt->maxsize; // circular queue
    pt->items[pt->rear] = x;
    pt->size++;

    printf("front = %d, rear = %d\n", pt->front, pt->rear);
    return true;
}

bool dequeue(ringbuffer *pt)
{
    if (isEmpty(pt)) 
    {
        return false;
    }

    printf("Removing %c\t", front(pt));

    pt->front = (pt->front + 1) % pt->maxsize; 
    pt->size--;

    printf("front = %d, rear = %d\n", pt->front, pt->rear);
    return true;
}
