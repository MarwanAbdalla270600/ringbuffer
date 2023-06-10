#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include "queue.h"
#include "memory/sharedMemory.h"

int main(int argc, char*argv[]) {


   
    if(argc > 2) {
        perror("ERROR: Invalid Argument\n\n");
        return -1;
    }

    int maxElements = atoi(argv[1]);
    int buffer = sizeof(queue) + (maxElements * sizeof(char));


    queue *ringbuffer = newQueue(maxElements);
    
    if(ringbuffer == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }

    int c;

    while((c = getchar()) != EOF && enqueue(ringbuffer, c));
    
    detachMemoryBlock(ringbuffer);
    return 0;
}