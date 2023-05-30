#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "memory/sharedMemory.h"
#include "queue.h"


int main() {
    queue *block = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }

    printQueue(block);

    return 0;
}