#include <stdio.h>
#include <stdlib.h>

struct LinkedList{ // 定义一个结构体, 因此house是一个自定义的数据类型.
    int value; // 4 bytes
    struct LinkedList *next; // 指针占 8 bytes
};

struct LinkedList *makeElement(int value){ // 创建LinkedList的每一个元素.
    struct LinkedList *element = malloc(sizeof(struct LinkedList)); // sizeof会申请 (4+8) 个bytes.
    element->value = value;
    element->next = NULL; // 默认为空.

    return element;
}

struct LinkedList *appendElement(struct LinkedList *first_element, int value){ // 在这个list的后面追加一个element, 返回的是first_element的地址..
    if (first_element == NULL){ // 如果第一个element是空的.
        return makeElement(value); // 则创建第一个element.
    }
    else{
        struct LinkedList *current = first_element;
        while (current->next != NULL){ // 找到最后一个element.
            current = current->next;
        }
        // while(current != NULL){ // 与上个while循环等价.
        //     if(current->next == NULL){
        //         break;
        //     }
        //     current = current->next;
        // }
        current->next = makeElement(value); // 在最后一个element上, 追加一个新的element.
    }

    return first_element;
}

struct LinkedList *makeList(struct LinkedList *first_element, int number, int values[]){ // LinkedList*返回的是first_element的地址.
    for (int i = 0; i < number; i++){
        first_element = appendElement(first_element, values[i]);
    }

    return first_element;
}

int len(struct LinkedList *first_element){ // 计算list的元素个数.
    int len = 0;
    struct LinkedList *current = first_element;
    while (current != NULL){
        len++;
        current = current->next;
    }

    return len;
}

void printList(struct LinkedList *first_element, int output){ // 打印lsit
    struct LinkedList *current = first_element; // 为防止 list = list->next时, 无法重新获取原始的list.
    int index = 0;
    while (current != NULL){
        printf("Output %d: The index is %d, the value is %d.\n", output, index++, current->value);
        current = current->next; // 为了防止找不到原始的list, 因此用一个current去承接next的赋值.
    }
    printf("Output %d: The length of this list is: %d.\n", output, index);
}

int main(void){
    struct LinkedList *list1 = NULL; // 声明第一个element的地址.
    list1 = appendElement(list1, 1);
    list1 = appendElement(list1, 2);
    list1 = appendElement(list1, 3);
    printList(list1, 1);

    printf("\n");

    struct LinkedList *list2 = NULL; // 声明第一个element的地址.
    int number = 5;
    int values[] = {7, 8, 9, 50, 25};
    list2 = makeList(list2, number, values);
    printList(list2, 2);

    // printf("Output 3: The length of list1 is: %d.\n", len(list1));
    // printf("Output 3: The length of list1 is: %d.\n", len(list2));
}