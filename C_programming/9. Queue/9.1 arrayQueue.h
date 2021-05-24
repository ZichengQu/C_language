#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// 9.1 arrayQueue描述的是利用Array实现queue的方式
// queue的特点是first in，first out

typedef struct arrayQueue* ArrayQueue;

/**
 * 创建queue
 */
ArrayQueue createArrayQueue();

/**
 * 入队
 * @param queue
 * @param data
 */
void enqueueArray(ArrayQueue queue, int data);

/**
 * 出队
 * @param queue
 */
int dequeueArray(ArrayQueue queue);

/**
 * 判断queue是否为空
 * @param queue
 */
bool isEmptyArrayQueue(ArrayQueue queue);

/**
 * 打印该queue的信息
 * @param queue
 */
void printArrayQueue(ArrayQueue queue);

/**
 * 释放queue所占的内存
 * @param queue
 */
void freeArrayQueue(ArrayQueue queue);