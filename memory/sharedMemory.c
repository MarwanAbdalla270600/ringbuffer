#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>

#include "../queue.h"
#include "sharedMemory.h"

#define IPC_RESULT_ERROR (-1)

static int getSharedBlock(char *filename, int size)
{
    key_t key;

    // Request a key
    // The key is linked to a filename, so that other programs can access it
    key = ftok(filename, 0);

    // get shared block --- create it if it doesn't exist

    return key == IPC_RESULT_ERROR? IPC_RESULT_ERROR : shmget(key, size, 0644 | IPC_CREAT);
}


queue *attachMemoryBlock(char *filename, int size)
{
    int sharedBlockId = getSharedBlock(filename, size);
    queue *result;                                                           
    if (sharedBlockId == IPC_RESULT_ERROR)
    {
        return NULL;
    }
    
    // map the shared block into this process's memory and give me a pointer to it
    result = (queue*) shmat(sharedBlockId, NULL, 0);
    if (result == (queue *)IPC_RESULT_ERROR)
    {
        return NULL;
    }
    return result;
}

bool detachMemoryBlock(queue* block) {
    return (shmdt(block) != IPC_RESULT_ERROR);
}

bool destroyMemoryBlock(char* filename) {
    int sharedBlockId = getSharedBlock(filename, 0);

    if(sharedBlockId == IPC_RESULT_ERROR) {
        return NULL;
    }
    return (shmctl(sharedBlockId, IPC_RMID, NULL) != IPC_RESULT_ERROR);
}