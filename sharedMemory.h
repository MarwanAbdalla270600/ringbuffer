#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#define BLOCK_SIZE 4096
#define FILENAME "sharedMemory.txt"

#include "ringbuffer.h"

ringbuffer *attachMemoryBlock(char *filename, int size);

bool detachMemoryBlock(ringbuffer* block);

#endif