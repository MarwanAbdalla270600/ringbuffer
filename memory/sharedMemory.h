#ifndef SHARED_MEMORY_H
#define SHARED_MEMORY_H

#define BLOCK_SIZE 4096
#define FILENAME "memory/sharedMemory.txt"

#include <stdbool.h>
#include <semaphore.h>
#include <sys/sem.h>
#include <fcntl.h>
#include <unistd.h>
#include "../queue.h"

queue *attachMemoryBlock(char *filename, int size);

bool detachMemoryBlock(queue* block);

bool destroyMemoryBlock(char* filename);

#endif