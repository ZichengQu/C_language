// #include <stdbool.h> // 已在h文件中定义
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <assert.h>

#include "9.2 listQueue.h"

// 9.2 listQueue描述的是利用List实现queue的方式
// queue的特点是first in，first out

typedef struct node* Node;
// typedef struct listQueue* ListQueue;  // 已在h文件中定义

struct node {   // 定义一个结构体, 因此node是一个自定义的数据类型.
    int value;  // 4 bytes
    Node next;  // 指针占 8 bytes
};

struct listQueue {
    Node front;
    Node rear;
};

/**
 * 创建queue
 */
ListQueue createListQueue() {
    ListQueue queue = malloc(sizeof(struct node));
    queue->front = NULL;
    queue->rear = NULL;
    return queue;
}

/**
 * 判断queue是否为空
 * @param queue
 */
bool isEmptyListQueue(ListQueue queue) {
    return queue->front == NULL;
}

/**
 * 入队
 * @param queue
 * @param data
 */
void enqueueList(ListQueue queue, int data) {
    Node node = (Node)malloc(sizeof(struct node));
    node->value = data;
    node->next = NULL;

    if(queue->front == NULL) {
        queue->front = node;
        queue->rear = node;
    } else {
        queue->rear->next = node;
        queue->rear = node;
    }
}

/**
 * 出队
 * @param queue
 */
int popListQueue(ListQueue queue) {
    Node firstNode;
    int pop_value;
    if(isEmptyListQueue(queue)) {
        printf("队列空");
        return -INFINITY;
    }
    firstNode = queue->front;
    if(queue->front == queue->rear) {
        queue->front = queue->rear = NULL;
    } else {
        queue->front = queue->front->next;
    }
    pop_value = firstNode->value;
    free(firstNode);
    return pop_value;
}

/**
 * 打印该queue的信息
 * @param queue
 */
void printListQueue(ListQueue queue) {
    assert(queue != NULL);
    printf("\t该queue的信息为 [第一个元素(栈顶元素)是最后插入的]: ");
    if(isEmptyListQueue(queue)) {
        printf("\tThis queue is empty.\n");
    } else {
        Node current = queue->front;  // 为防止 list = list->next时, 无法重新获取原始的list.
        while(current != NULL) {
            printf("%d ", current->value);
            current = current->next;  // 为了防止找不到原始的list, 因此用一个current去承接next的赋值.
        }
        printf("\n");
    }
}

/**
 * 释放queue所占的内存
 * @param queue
 */
void freeListQueue(ListQueue queue) {
    assert(queue != NULL);
    if(queue != NULL) {
        Node current = queue->front;
        while(current != NULL) {  // free掉该queue中的每一个node.
            Node next = current->next;
            free(current);
            current = next;
        }
        free(queue);  // free掉该queue的空间.
    }
}