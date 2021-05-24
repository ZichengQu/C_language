#include <assert.h>
#include <math.h>
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// #include "8.2 listStack.h"

// 8.2 listStack描述的是利用List实现stack的方式
// stack的特点是first in，last out

typedef struct listStack* ListStack;  // 通过这个定义后，struct node* 与 ListStack在使用上等价.

/**
 * 创建stack
 */
ListStack createListStack();

/**
 * 判断stack是否为空
 * @param stack
 */
bool isEmptyListStack(ListStack stack);

/**
 * 压栈
 * @param stack
 * @param data
 */
void pushListStack(ListStack stack, int data);

/**
 * 弹栈
 * @param stack
 */
int popListStack(ListStack stack);

/**
 * 打印该stack的信息
 * @param stack
 */
void printListStack(ListStack stack);

/**
 * 释放stack所占的内存
 * @param stack
 */
void freeListStack(ListStack stack);