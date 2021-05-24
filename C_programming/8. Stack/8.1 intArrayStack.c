#include "8.1 intArrayStack.h"

// 8.1 intArrayStack描述的是利用Array实现stack的方式，存储的是int
// stack的特点是first in，last out

#define ARRAY_LEN 1024

// typedef struct intArrayStack* IntArrayStack; // 在h文件中定义了

struct intArrayStack {
    int array[ARRAY_LEN];
    int index;
};

/**
 * 创建stack
 */
IntArrayStack createIntArrayStack() {
    IntArrayStack stack = malloc(sizeof(struct intArrayStack));
    stack->index = -1;
    return stack;
}

/**
 * 压栈
 * @param stack
 * @param data
 */
void pushIntArrayStack(IntArrayStack stack, int data) {
    assert(stack->index < ARRAY_LEN - 1);
    stack->array[++stack->index] = data;
}

/**
 * 弹栈
 * @param stack
 */
int popIntArrayStack(IntArrayStack stack) {
    assert(stack->index > -1);
    int result = stack->array[stack->index--];

    return result;
}

/**
 * 判断栈是否为空
 * @param stack
 */
bool isEmptyIntArrayStack(IntArrayStack stack) {
    return stack->index == -1 ? true : false;
}

/**
 * 打印该stack的信息
 * @param stack
 */
void printIntArrayStack(IntArrayStack stack) {
    assert(stack != NULL);
    printf("该stack的信息为:\n");
    if(stack->index == -1) {
        printf("\tThis stack is empty.\n");
    } else {
        printf("\tThe index of this stack is %d;\n", stack->index);
        for(int i = 0; i <= stack->index; i++) {
            printf("\t第%d个元素的值是%d;\n", i, stack->array[i]);
        }
    }
}

/**
 * 释放stack所占的内存
 * @param stack
 */
void freeIntArrayStack(IntArrayStack stack) {
    assert(stack != NULL);
    free(stack);
}