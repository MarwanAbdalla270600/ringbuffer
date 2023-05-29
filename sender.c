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

    char* block = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }
    //block = pt;

    printf("Writing: %s\n", argv[1]);
    strncpy(block, argv[1], BLOCK_SIZE);

    detachMemoryBlock(block);
    return 0;
}