#include <stdio.h>

#include "9.1 arrayQueue.h"

int main(int argc, char** argv) {
    ArrayQueue arrayQueue = createArrayQueue();
    enqueueArray(arrayQueue, 3);
    enqueueArray(arrayQueue, 5);
    enqueueArray(arrayQueue, 1);
    enqueueArray(arrayQueue, 9);
    enqueueArray(arrayQueue, 7);

    printArrayQueue(arrayQueue);

    while(isEmptyArrayQueue(arrayQueue) == false) {
        int result = dequeueArray(arrayQueue);
        printf("从queue中dequeue: %d;\n", result);
    }

    freeArrayQueue(arrayQueue);

    return 0;
}