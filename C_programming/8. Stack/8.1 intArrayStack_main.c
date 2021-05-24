#include <stdio.h>

#include "8.1 intArrayStack.h"

int main(int argc, char** argv) {
    IntArrayStack intArrayStack = createIntArrayStack();
    pushIntArrayStack(intArrayStack, 1);
    pushIntArrayStack(intArrayStack, 2);
    pushIntArrayStack(intArrayStack, 3);
    pushIntArrayStack(intArrayStack, 4);
    pushIntArrayStack(intArrayStack, 5);

    printIntArrayStack(intArrayStack);

    while(isEmptyIntArrayStack(intArrayStack) == false) {
        int result = popIntArrayStack(intArrayStack);
        printf("从stack中pop: %d;\n", result);
    }

    freeIntArrayStack(intArrayStack);

    return 0;
}