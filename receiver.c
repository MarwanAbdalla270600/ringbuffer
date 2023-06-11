#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "memory/sharedMemory.h"


int main(int argc, char*argv[]) {


    if(argc != 1) {
        perror("ERROR: Invalid Argument\n\n");
        return -1;
    }


    queue *block = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }

        //sleep(1); //enable for showcase
    while(dequeue(block));
    
    detachMemoryBlock(block);
    return 0;
}