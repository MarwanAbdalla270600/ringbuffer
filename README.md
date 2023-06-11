gcc -Wall -Wextra -pedantic -Wno-unused-parameter ringbuffer.c sharedMemory.c sender.c -o ./sender

gcc -Wall -Wextra -pedantic -Wno-unused-parameter ringbuffer.c sharedMemory.c receiver.c -o ./receiver
