// #include <stdbool.h> // 已在h文件中定义
// #include <stdio.h>
// #include <stdlib.h>
// #include <math.h>
// #include <assert.h>

#include "8.2 listStack.h"

// 8.2 listStack描述的是利用List实现stack的方式
// stack的特点是first in，last out

typedef struct node* Node;  // 通过这个定义后，struct node* 与 Node在使用上等价. 已在h文件中定义
// typedef struct listStack* ListStack;  // 已在h文件中定义

struct node {   // 定义一个结构体, 因此node是一个自定义的数据类型.
    int value;  // 4 bytes
    Node next;  // 指针占 8 bytes
};

struct listStack {
    Node front;  // 压栈和弹栈都在LinkedList的头节点进行操作，该头节点只存储list中的firstNode，不存储value。每回压栈和弹栈都通过该front找到list中的firstNode.
};

/**
 * 创建stack
 */
ListStack createListStack() {
    ListStack stack = malloc(sizeof(struct listStack));
    stack->front = NULL;
    return stack;
}

/**
 * 判断stack是否为空
 * @param stack
 */
bool isEmptyListStack(ListStack stack) {
    return stack->front == NULL;
}

/**
 * 压栈
 * @param stack
 * @param data
 */
void pushListStack(ListStack stack, int data) {
    Node node = (Node)malloc(sizeof(struct node));
    node->value = data;
    node->next = stack->front;
    stack->front = node;
}

/**
 * 弹栈
 * @param stack
 */
int popListStack(ListStack stack) {
    Node firstNode;
    int pop_value;
    if(isEmptyListStack(stack)) {
        printf("堆栈空");
        return -INFINITY;
    } else {
        firstNode = stack->front;
        stack->front = firstNode->next;
        pop_value = firstNode->value;
        free(firstNode);
        return pop_value;
    }
}

/**
 * 打印该stack的信息
 * @param stack
 */
void printListStack(ListStack stack) {
    assert(stack != NULL);
    printf("\t该stack的信息为 [第一个元素(栈顶元素)是最后插入的]: ");
    if(isEmptyListStack(stack)) {
        printf("\tThis stack is empty.\n");
    } else {
        Node current = stack->front;  // 为防止 list = list->next时, 无法重新获取原始的list.
        while(current != NULL) {
            printf("%d ", current->value);
            current = current->next;  // 为了防止找不到原始的list, 因此用一个current去承接next的赋值.
        }
        printf("\n");
    }
}

/**
 * 释放stack所占的内存
 * @param stack
 */
void freeListStack(ListStack stack) {
    assert(stack != NULL);
    if(stack != NULL) {
        Node current = stack->front;
        while(current != NULL) {  // free掉该stack中的每一个node.
            Node next = current->next;
            free(current);
            current = next;
        }
        free(stack);  // free掉该stack的空间.
    }
}