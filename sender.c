#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sharedMemory.h"
#include "ringbuffer.h"


int main(int argc, char*argv[]) {

    int size = atoi(argv[1]);
    ringbuffer *ringbufferVar = newringbuffer(size);
    
    ringbuffer *memory = attachMemoryBlock("sharedMemory.txt", BLOCK_SIZE);
    if(memory == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }

    int c;

    while((c = getchar()) != EOF) {
        enqueue(ringbufferVar, c);
    }
        
    
    *memory = *ringbufferVar;
    strcpy(memory->items, ringbufferVar->items);

    detachMemoryBlock(memory);
    return 0;
}