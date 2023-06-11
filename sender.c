#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <sys/mman.h>
#include <semaphore.h>
#include "queue.h"
#include "memory/sharedMemory.h"

int main(int argc, char*argv[]) {

    if(argc != 2) {
        perror("ERROR: Invalid Argument\n\n");
        return -1;
    }

    //setup some semaphore
    sem_t *sem_sender = sem_open(SEM_SENDER, O_CREAT, 0660, 0);
    if(sem_sender == SEM_FAILED) {
        perror("sem_open/sender");
        exit(EXIT_FAILURE);
    }

    sem_t *sem_receiver = sem_open(SEM_RECEIVER, O_CREAT, 0660, 0);
    if(sem_receiver == SEM_FAILED) {
        perror("sem_open/receiver");
        exit(EXIT_FAILURE);
    }

    int maxElements = atoi(argv[1]);
    queue *ringbuffer = newQueue(maxElements);
    
    if(ringbuffer == NULL) {
        perror("ERROR: could not get block\n");
        return -1;
    }

    int c;


    while((c = getchar()) != EOF) {

       sem_wait(sem_receiver);
       enqueue(ringbuffer, c);
       sem_post(sem_sender);

    }

   
    sem_close(sem_sender);
    sem_close(sem_receiver);
    detachMemoryBlock(ringbuffer);
    return 0;
}