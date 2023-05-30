
#include <stdio.h>
#include <stdlib.h>
#include "queue.h"


// Utility function to initialize a queue
queue *newQueue(int size)
{
    queue *pt = NULL;
    pt = malloc(sizeof(queue));
    pt->maxsize = size;
    pt->front = 0;
    pt->rear = -1;
    pt->size = 0;

    return pt;
}

// Utility function to return the size of the queue
int size(queue *pt)
{
    return pt->size;
}

// Utility function to check if the queue is empty or not
bool isEmpty(queue *pt)
{
    return !size(pt);
}

// Utility function to return the front element of the queue
char front(queue *pt)
{
    if (isEmpty(pt))
    {
        printf("Underflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    return pt->items[pt->front];
}

// Utility function to add an element `x` to the queue
void enqueue(queue *pt, char x)
{
    if (size(pt) == pt->maxsize)
    {
        printf("Overflow\nProgram Terminated\n");
        exit(EXIT_FAILURE);
    }

    printf("Inserting %c\t", x);

    pt->rear = (pt->rear + 1) % pt->maxsize; // circular queue
    pt->items[pt->rear] = x;
    pt->size++;

    printf("front = %d, rear = %d\n", pt->front, pt->rear);
}

// Utility function to dequeue the front element
bool dequeue(queue *pt)
{
    if (isEmpty(pt)) // front == rear
    {
        printf("Underflow\nProgram Terminated\n");
        return false;
    }

    printf("Removing %c\t", front(pt));

    pt->front = (pt->front + 1) % pt->maxsize; // circular queue
    pt->size--;

    printf("front = %d, rear = %d\n", pt->front, pt->rear);
    return true;
}


void printQueue(queue *pt) {
    if(pt->size == 0) {
        printf("QUEUE IS EMPTY\n");
        return;
    }
    printf("\tQUEUE\n");
    for(int i=pt->front; i<=pt->rear; i++) {
        printf("\t%c\tindex = %i\n", pt->items[i], i);
    }
}
