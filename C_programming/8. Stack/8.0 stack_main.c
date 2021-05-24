#include <stdio.h>

#include "8.1 arrayStack.h"
#include "8.2 listStack.h"

int main(int argc, char** argv) {
    printf("通过8.1 Array实现Stack:\n");
    ArrayStack arrayStack = createArrayStack();
    pushArrayStack(arrayStack, 1);
    pushArrayStack(arrayStack, 2);
    pushArrayStack(arrayStack, 3);
    pushArrayStack(arrayStack, 4);
    pushArrayStack(arrayStack, 5);

    printArrayStack(arrayStack);

    while(isEmptyArrayStack(arrayStack) == false) {
        int result = popArrayStack(arrayStack);
        printf("\t从stack中pop: %d;\n", result);
    }

    freeArrayStack(arrayStack);

    printf("通过8.2 List实现Stack:\n");
    ListStack listStack = createListStack();
    pushListStack(listStack, 1);
    pushListStack(listStack, 2);
    pushListStack(listStack, 3);
    pushListStack(listStack, 4);
    pushListStack(listStack, 5);

    printListStack(listStack);

    while(isEmptyListStack(listStack) == false) {
        int result = popListStack(listStack);
        printf("\t从stack中pop: %d;\n", result);
    }

    freeListStack(listStack);

    return 0;
}