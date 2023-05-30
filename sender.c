#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "queue.h"
#include "memory/sharedMemory.h"

int main(int argc, char*argv[]) {

   
    if(argc > 2) {
        perror("ERROR: Invalid Argument\n\n");
        return -1;
    }



    queue *pt = newQueue(buffersize);

    int c;

    while((c = getchar()) != EOF) {
        enqueue(pt, c);
    }


    queue* block = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    
    if(block == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }
   
    *block = *pt;

    free(pt);

    detachMemoryBlock(block);
    return 0;
}