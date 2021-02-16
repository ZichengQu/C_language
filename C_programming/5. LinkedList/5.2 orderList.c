#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

#include "5.2 orderList.h" // 标准类库用<>, 自定义的h文件用双引号.

typedef struct node* Node; // 不开放给其他人使用, 只能在本文件中使用.
// typedef struct LinkedList* LinkedList; // 放入h文件, 开放给其他人使用, 可以在其它文件中使用.

struct node{
    double money;
    char* array;
    Node next;
};

struct LinkedList{
    int len;
    Node first_node;
    Node last_node;
};

Node newNode(double money, char* array){
    Node node = malloc(sizeof(struct node));

    node->money = money;

    node->array = malloc(sizeof(char) * (strlen(array) + 1)); // 加 1 是因为 \0
    strcpy(node->array, array);
    node->array[strlen(array)] = '\0'; // 不同的OS可能对strcpy的优化不一样, 因此最好手动在最后补齐一个 \0

    node->next = NULL;

    return node;
}

LinkedList newList(){
    LinkedList list = malloc(sizeof(struct LinkedList)); 
    list->len = 0;
    list->first_node = NULL;
    list->last_node = NULL;

    return list;
}

int compareTo(Node first, Node second){ // 对比两个Node的value1的大小
    assert(first != NULL && second != NULL);
    // 根据两个Node的money和array进行比较
    // 假设此例的money的优先级大于array(先根据money的大小进行排序, 若money一致, 则根据array的大小进行排序).
    // 如果first.money比second.money小, 返回 -1
    // 如果first.money比second.money大, 返回  1
    // 如果两者的money相等:
            // 如果first.array比second.array小, 返回 -1
            // 如果first.array比second.array大, 返回  1
    // 如果两者的money和array均相等, 则返回 0
    // 类似于strcmp
    int result = 0;
    if (first->money < second->money){
        result = -1;
    }else if(first->money > second->money){
        result = 1;
    }else{
       result = strcmp(first->array, second->array); // first.array > second.array? 1: (first.array < second.array? -1: 0)
    }
    return result;
}

/**
 * 假设此例的 money 的优先级大于 array.
 * 先根据 money 的大小进行排序,.
 * 若 money 一致, 则根据 array 的大小进行排序.
 */
void appendByOrder(LinkedList list, double money, char* array){ // 有序递增插入
    Node new_node = newNode(money, array);
    if (list->first_node == NULL){ // 如果第一个node是空的.
        list->first_node = new_node; // 则创建第一个node.
        list->last_node = list->first_node; // 因为此时该list只有一个node, 所有其最后一个node和第一个node是同一个node.
    }else{
        if(compareTo(new_node, list->first_node) < 0){ // new_node的value1比first_node的value1还小.
            new_node->next = list->first_node;
            list->first_node = new_node;
        }else if(compareTo(new_node, list->last_node) > 0){ // new_node的value1比last_node的value1还大.
            list->last_node->next = new_node; // 将新节点与list->last_node建立连接.
            list->last_node = new_node; // 更新list->last_node为new_node.
        }else{
            Node pre = list->first_node;
            Node current = list->first_node->next;
            while (current != NULL)
            { // 当current不为空时
                if (compareTo(new_node, pre) >= 0 && compareTo(new_node, current) <= 0){ // if(new_node->array >= pre->array && new_node->array <= current->array)
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

void printList(LinkedList list){
    Node current = list->first_node;
    int index = 0;
    while (current != NULL){
        printf("index: %d, money: %lf, array: %s\n", index++, current->money, current->array);
        current = current->next;
    }
    printf("The length of this list: %d.\n", list->len);
}

void freeList(LinkedList list){
    if(list != NULL){
        Node current = list->first_node;
        while (current != NULL){
            Node next = current->next;
            free(current->array);
            free(current);
            current = next;
        }
        free(list);
    }
}