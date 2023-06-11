#include "ringbuffer.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "sharedMemory.h"

int main(int argc, char *argv[])
{

    ringbuffer *memory = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    if (memory == NULL)
    {
        perror("ERROR: could not get block\n");
        return -1;
    }

    while (dequeue(memory));

    detachMemoryBlock(memory);
    return 0;
}