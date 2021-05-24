#include <stdio.h>

#include "8.1 arrayStack.h"

// 8.1 arrayStack描述的是利用Array实现stack的方式
// stack的特点是first in，last out

#define ARRAY_LEN 1024

// typedef struct arrayStack* ArrayStack; // 在h文件中定义了

struct arrayStack {
    int array[ARRAY_LEN];
    int index;
};

/**
 * 创建stack
 */
ArrayStack createArrayStack() {
    ArrayStack stack = malloc(sizeof(struct arrayStack));
    stack->index = -1;
    return stack;
}

/**
 * 压栈
 * @param stack
 * @param data
 */
void pushArrayStack(ArrayStack stack, int data) {
    assert(stack->index < ARRAY_LEN - 1);
    stack->array[++stack->index] = data;
}

/**
 * 弹栈
 * @param stack
 */
int popArrayStack(ArrayStack stack) {
    assert(stack->index > -1);
    int result = stack->array[stack->index--];

    return result;
}

/**
 * 判断stack是否为空
 * @param stack
 */
bool isEmptyArrayStack(ArrayStack stack) {
    return stack->index == -1 ? true : false;
}

/**
 * 打印该stack的信息
 * @param stack
 */
void printArrayStack(ArrayStack stack) {
    assert(stack != NULL);
    printf("\t该stack的信息为(从栈底开始打印):\n");
    if(stack->index == -1) {
        printf("\t\tThis stack is empty.\n");
    } else {
        printf("\t\tThe index of this stack is %d;\n", stack->index);
        for(int i = 0; i <= stack->index; i++) {
            printf("\t\t第%d个元素的值是%d;\n", i, stack->array[i]);
        }
    }
}

/**
 * 释放stack所占的内存
 * @param stack
 */
void freeArrayStack(ArrayStack stack) {
    assert(stack != NULL);
    free(stack);
}