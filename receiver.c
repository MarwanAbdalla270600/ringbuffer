#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "memory/sharedMemory.h"


int main(int argc, char*argv[]) {

    //queue* q;

    if(argc != 1) {
        perror("ERROR: Invalid Argument\n\n");
        return -1;
    }

    queue *block = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }
    //q = block;

    printf("Reading: %d\n", block->maxsize);
    printf("Reading: %d\n", block->rear);

    for(int i=0; i<block->size; i++) {
       dequeue(block);
    }
    //printQueue(block);
    detachMemoryBlock(block);
    return 0;
}