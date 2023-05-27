#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/types.h>
#include <sys/ipc.h>
#include <sys/shm.h>
#include "sharedMemory.h"

#define IPC_RESULT_ERROR (-1)

static int getSharedBlock(char *filename, int size)
{
    key_t key;

    // Request a key
    // The key is linked to a filename, so that other programs can access it
    key = ftok(filename, 0);
    if (key == IPC_RESULT_ERROR)
    {
        return IPC_RESULT_ERROR;
    }

    // get shared block --- create it if it doesn't exist
    return shmget(key, size, 0644 | IPC_CREAT);
}

char *attachMemoryBlock(char *filename, int size)
{
    int sharedBlockId = getSharedBlock(filename, size);
    char *result;

    if (sharedBlockId == IPC_RESULT_ERROR)
    {
        return NULL;
    }

    // map the shared block into this process's memory and give me a pointer to it
    result = shmat(sharedBlockId, NULL, 0);
    if (result == (char *)IPC_RESULT_ERROR)
    {
        return NULL;
    }
    return result;
}
