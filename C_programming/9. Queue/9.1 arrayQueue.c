#include <stdio.h>

#include "9.1 arrayQueue.h"

// 9.1 arrayQueue描述的是利用Array实现queue的方式
// queue的特点是first in，first out

#define ARRAY_LEN 1024

// typedef struct arrayQueue* ArrayQueue; // 在h文件中定义了

struct arrayQueue {
    int array[ARRAY_LEN];
    int index;
};

/**
 * 创建queue
 */
ArrayQueue createArrayQueue() {
    ArrayQueue queue = malloc(sizeof(struct arrayQueue));
    queue->index = -1;
    return queue;
}

/**
 * 入队
 * @param queue
 * @param data
 */
void enqueueArray(ArrayQueue queue, int data) {
    assert(queue->index < ARRAY_LEN - 1);
    queue->array[++queue->index] = data;
}

/**
 * 出队
 * @param queue
 */
int dequeueArray(ArrayQueue queue) {
    assert(queue->index > -1);

    int result = queue->array[0];

    for(int i = 1; i <= queue->index; i++) {
        queue->array[i - 1] = queue->array[i];  // 可使用循环队列进行优化
    }
    queue->index--;

    return result;
}

/**
 * 判断queue是否为空
 * @param queue
 */
bool isEmptyArrayQueue(ArrayQueue queue) {
    return queue->index == -1 ? true : false;
}

/**
 * 打印该queue的信息
 * @param queue
 */
void printArrayQueue(ArrayQueue queue) {
    assert(queue != NULL);
    printf("\t该queue的信息为:\n");
    if(queue->index == -1) {
        printf("\t\tThis queue is empty.\n");
    } else {
        printf("\t\tThe index of this queue is %d;\n", queue->index);
        for(int i = 0; i <= queue->index; i++) {
            printf("\t\t第%d个元素的值是%d;\n", i, queue->array[i]);
        }
    }
}

/**
 * 释放queue所占的内存
 * @param queue
 */
void freeArrayQueue(ArrayQueue queue) {
    assert(queue != NULL);
    free(queue);
}