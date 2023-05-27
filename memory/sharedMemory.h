#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#define BLOCK_SIZE 4096
#define FILENAME "memory/sharedMemory.txt"
#include <stdbool.h>

char* attachMemoryBlock(char* filename, int size);

bool detachMemoryBlock(char* block);

bool destroyMemoryBlock(char* filename);

#endif