#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#define BLOCK_SIZE 4096
#define FILENAME "sharedMemory.txt"

char* attachMemoryBlock(char* filename, int size);

bool detachMemoryBlock(char* block);

bool destroyMemoryBlock(char* filename);

#endif