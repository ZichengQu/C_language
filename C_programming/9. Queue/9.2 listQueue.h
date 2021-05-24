#include <stdbool.h> // 已在h文件中定义
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>

// 9.2 listQueue描述的是利用List实现queue的方式
// queue的特点是first in，first out

typedef struct listQueue* ListQueue;

/**
 * 创建queue
 */
ListQueue createListQueue();

/**
 * 判断queue是否为空
 * @param queue
 */
bool isEmptyListQueue(ListQueue queue);

/**
 * 入队
 * @param queue
 * @param data
 */
void enqueueList(ListQueue queue, int data);

/**
 * 出队
 * @param queue
 */
int popListQueue(ListQueue queue);

/**
 * 打印该queue的信息
 * @param queue
 */
void printListQueue(ListQueue queue);

// /**
//  * 释放queue所占的内存
//  * @param queue
//  */
// void freeListQueue(ListQueue queue) {
//     assert(queue != NULL);
//     if(queue != NULL) {
//         ListQueue current = queue->next;
//         while(current != NULL) {  // free掉该queue中的每一个node.
//             ListQueue next = current->next;
//             free(current);
//             current = next;
//         }
//         free(queue);  // free掉该queue的空间.
//     }
// }