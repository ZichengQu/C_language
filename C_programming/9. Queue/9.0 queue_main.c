#include "9.1 arrayQueue.h"
#include "9.2 listQueue.h"

int main(int argc, char** argv) {
    printf("通过9.1 Array实现Queue:\n");
    ArrayQueue arrayQueue = createArrayQueue();
    enqueueArray(arrayQueue, 3);
    enqueueArray(arrayQueue, 5);
    enqueueArray(arrayQueue, 1);
    enqueueArray(arrayQueue, 9);
    enqueueArray(arrayQueue, 7);

    printArrayQueue(arrayQueue);

    while(isEmptyArrayQueue(arrayQueue) == false) {
        int result = dequeueArray(arrayQueue);
        printf("\t从queue中dequeue: %d;\n", result);
    }

    freeArrayQueue(arrayQueue);

    printf("通过9.2 List实现Queue:\n");
    ListQueue listQueue = createListQueue();
    enqueueList(listQueue, 5);
    enqueueList(listQueue, 2);
    enqueueList(listQueue, 3);
    enqueueList(listQueue, 4);
    enqueueList(listQueue, 1);

    printListQueue(listQueue);

    while(isEmptyListQueue(listQueue) == false) {
        int result = popListQueue(listQueue);
        printf("\t从queue中dequeue: %d;\n", result);
    }

    // freeListQueue(listQueue);

    return 0;
}