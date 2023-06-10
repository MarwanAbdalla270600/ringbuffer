#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "queue.h"
#include "memory/sharedMemory.h"


int main(int argc, char*argv[]) {


    if(argc != 1) {
        perror("ERROR: Invalid Argument\n\n");
        return -1;
    }

    //setup some semaphore
    //sem_unlink(SEM_RECEIVER);
    //sem_unlink(SEM_SENDER);

    sem_t *sem_sender = sem_open(SEM_SENDER, O_CREAT, 0660, 0);
    if(sem_sender == SEM_FAILED) {
        perror("sem_open/sender");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_receiver = sem_open(SEM_RECEIVER, O_CREAT, 0660, 1);
    if(sem_receiver == SEM_FAILED) {
        perror("sem_open/receiver");
        exit(EXIT_FAILURE);
    }


    queue *block = attachMemoryBlock(FILENAME, BLOCK_SIZE);
    if(block == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }

    while (true) {
        sem_wait(sem_receiver);
        //sleep(1);
        dequeue(block);
        sem_post(sem_sender);
    }
     
    sem_close(sem_sender);
    sem_close(sem_receiver);
    detachMemoryBlock(block);
    return 0;
}