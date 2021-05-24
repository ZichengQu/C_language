#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// 8.1 intArrayStack描述的是利用Array实现stack的方式，存储的是int
// stack的特点是first in，last out

typedef struct intArrayStack* IntArrayStack;

/**
 * 创建stack
 */
IntArrayStack createIntArrayStack();

/**
 * 压栈
 * @param stack
 * @param data
 */
void pushIntArrayStack(IntArrayStack stack, int data);

/**
 * 弹栈
 * @param stack
 */
int popIntArrayStack(IntArrayStack stack);

/**
 * 判断栈是否为空
 * @param stack
 */
bool isEmptyIntArrayStack(IntArrayStack stack);

/**
 * 打印该stack的信息
 * @param stack
 */
void printIntArrayStack(IntArrayStack stack);

/**
 * 释放stack所占的内存
 * @param stack
 */
void freeIntArrayStack(IntArrayStack stack);