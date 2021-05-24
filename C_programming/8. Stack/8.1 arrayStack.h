#include <assert.h>
#include <stdbool.h>
#include <stdlib.h>

// 8.1 arrayStack描述的是利用Array实现stack的方式
// stack的特点是first in，last out

typedef struct arrayStack* ArrayStack;

/**
 * 创建stack
 */
ArrayStack createArrayStack();

/**
 * 压栈
 * @param stack
 * @param data
 */
void pushArrayStack(ArrayStack stack, int data);

/**
 * 弹栈
 * @param stack
 */
int popArrayStack(ArrayStack stack);

/**
 * 判断stack是否为空
 * @param stack
 */
bool isEmptyArrayStack(ArrayStack stack);

/**
 * 打印该stack的信息
 * @param stack
 */
void printArrayStack(ArrayStack stack);

/**
 * 释放stack所占的内存
 * @param stack
 */
void freeArrayStack(ArrayStack stack);