#include <stdio.h>
#include "memory/sharedMemory.h"

int main(int argc, char *argv[]) {

    if(argc != 1) {
        perror("Invalid Arguments\n");
        return -1;
    }

    if(destroyMemoryBlock(FILENAME)) {
        printf("Destroyed block %s\n", FILENAME);
    } else {
        printf("Could not destroy block %s\n", FILENAME);
    }

    return 0;

}