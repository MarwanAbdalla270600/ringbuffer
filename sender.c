#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "memory/sharedMemory.h"

int main(int argc, char*argv[]) {

   
    if(argc != 2) {
        perror("ERROR: Invalid Argument\n\n");
        return -1;
    }


    queue *pt = newQueue(5);

    enqueue(pt, 'a');
    enqueue(pt, 'b');
    enqueue(pt, 'c');
    enqueue(pt, 'd');




    queue* block = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    //block->items = (char*) malloc(sizeof(char) * 100);
    //strncpy(block->items, pt->items, strlen(pt->items));
    if(block == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }
    //block = pt;

    //printf("Writing: %s\n", argv[1]);
    //strncpy(block, argv[1], BLOCK_SIZE);

    *block = *pt;

    printQueue(block);

    detachMemoryBlock(block);
    return 0;
}