Diese Version ist ohne Semaphoren, da diese nicht korrekt bei mir funktioniert haben.
in input.txt befinden sich 590 characters
./script.sh     zum komplilieren der dateien
./sender x < input.txt      x... größe des ringbuffers
./receiver      entehrt den ringbuffer
./destroy       zerstört den sharedMemory