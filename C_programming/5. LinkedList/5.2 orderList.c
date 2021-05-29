#include <assert.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "5.2 orderList.h"  // 标准类库用<>, 自定义的h文件用双引号.

typedef struct node* Node;  // 不开放给其他人使用, 只能在本文件中使用.
// typedef struct LinkedList* LinkedList; // 放入h文件, 开放给其他人使用, 可以在其它文件中使用.

struct node {
    double value;  // value1
    char* string;  // value2
    Node next;
};

struct LinkedList {
    int len;
    Node first_node;
    Node last_node;
};

Node newNode(double value, char* string) {
    Node node = malloc(sizeof(struct node));

    node->value = value;

    node->string = malloc(sizeof(char) * (strlen(string) + 1));  // 加 1 是因为 \0
    strcpy(node->string, string);
    node->string[strlen(string)] = '\0';  // 不同的OS可能对strcpy的优化不一样, 因此最好手动在最后补齐一个 \0

    node->next = NULL;

    return node;
}

LinkedList newList() {
    LinkedList list = malloc(sizeof(struct LinkedList));
    list->len = 0;
    list->first_node = NULL;
    list->last_node = NULL;

    return list;
}

int compareTo(Node first, Node second) {  // 对比两个Node的value1的大小
    assert(first != NULL && second != NULL);
    // 根据两个Node的value和string进行比较
    // 假设此例的value的优先级大于string(先根据value的大小进行排序, 若value一致, 则根据string的大小进行排序).
    // 如果first.value比second.value小, 返回 -1
    // 如果first.value比second.value大, 返回  1
    // 如果两者的value相等:
    // 如果first.string比second.string小, 返回 -1
    // 如果first.string比second.string大, 返回  1
    // 如果两者的value和string均相等, 则返回 0
    // 类似于strcmp
    int result = 0;
    if(first->value < second->value) {
        result = -1;
    } else if(first->value > second->value) {
        result = 1;
    } else {
        result = strcmp(first->string, second->string);  // first.string > second.string? 1: (first.string < second.string? -1: 0)
    }
    return result;
}

/**
 * 假设此例的 value 的优先级大于 string.
 * 先根据 value 的大小进行排序,.
 * 若 value 一致, 则根据 string 的大小进行排序.
 */
void appendByOrder(LinkedList list, double value, char* string) {  // 有序递增插入
    Node new_node = newNode(value, string);
    if(list->first_node == NULL) {           // 如果第一个node是空的.
        list->first_node = new_node;         // 则创建第一个node.
        list->last_node = list->first_node;  // 因为此时该list只有一个node, 所有其最后一个node和第一个node是同一个node.
    } else {
        if(compareTo(new_node, list->first_node) < 0) {  // new_node的value1比first_node的value1还小.
            new_node->next = list->first_node;
            list->first_node = new_node;
        } else if(compareTo(new_node, list->last_node) > 0) {  // new_node的value1比last_node的value1还大.
            list->last_node->next = new_node;                  // 将新节点与list->last_node建立连接.
            list->last_node = new_node;                        // 更新list->last_node为new_node.
        } else {
            Node pre = list->first_node;
            Node current = list->first_node->next;
            while(current != NULL) {                                                      // 当current不为空时
                if(compareTo(new_node, pre) >= 0 && compareTo(new_node, current) <= 0) {  // if(new_node->string >= pre->string && new_node->string <= current->string)
                    break;
                }
                pre = pre->next;
                current = current->next;
            }
            pre->next = new_node;
            new_node->next = current;
        }
    }
    list->len++;
}

void printList(LinkedList list) {
    Node current = list->first_node;
    int index = 0;
    while(current != NULL) {
        printf("index: %d, value: %lf, string: %s\n", index++, current->value, current->string);
        current = current->next;
    }
    printf("The length of this list: %d.\n", list->len);
}

void freeList(LinkedList list) {
    if(list != NULL) {
        Node current = list->first_node;
        while(current != NULL) {
            Node next = current->next;
            free(current->string);
            free(current);
            current = next;
        }
        free(list);
    }
}