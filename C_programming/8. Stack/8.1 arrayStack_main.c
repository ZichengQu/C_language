#include <stdio.h>

#include "8.1 arrayStack.h"

int main(int argc, char** argv) {
    ArrayStack arrayStack = createArrayStack();
    pushArrayStack(arrayStack, 1);
    pushArrayStack(arrayStack, 2);
    pushArrayStack(arrayStack, 3);
    pushArrayStack(arrayStack, 4);
    pushArrayStack(arrayStack, 5);

    printArrayStack(arrayStack);

    while(isEmptyArrayStack(arrayStack) == false) {
        int result = popArrayStack(arrayStack);
        printf("从stack中pop: %d;\n", result);
    }

    freeArrayStack(arrayStack);

    return 0;
}