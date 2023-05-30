#!/bin/bash
gcc -Wall -Wextra -pedantic -Wno-unused-parameter queue.c memory/sharedMemory.c sender.c -o ./sender

gcc -Wall -Wextra -pedantic -Wno-unused-parameter queue.c memory/sharedMemory.c receiver.c -o ./receiver

gcc -Wall -Wextra -pedantic -Wno-unused-parameter destroyMemory.c memory/sharedMemory.c -o ./destroy

gcc -Wall -Wextra -pedantic -Wno-unused-parameter queue.c memory/sharedMemory.c print.c -o ./print

echo "all files compiled successfully"