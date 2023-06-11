#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "sharedMemory.h"
#include "ringbuffer.h"

#define ERROR (-1)


ringbuffer *attachMemoryBlock(char *filename, int size)
{
    key_t key;
    key = ftok(filename, 0);
    key = shmget(key, size, 0644 | IPC_CREAT);
    int sharedBlockId = key;
    ringbuffer *result;                                                           
    if (sharedBlockId == ERROR)
    {
        return NULL;
    }
    
    result = (ringbuffer*) shmat(sharedBlockId, NULL, 0);
    if (result == (ringbuffer *)ERROR)
    {
        return NULL;
    }
    return result;
}

bool detachMemoryBlock(ringbuffer* block) {
    return (shmdt(block) != ERROR);
}
