#include <stdio.h>
#include <stdlib.h>
#include <assert.h>

#include "5.2 orderList.h" // 标准类库用<>, 自定义的h文件用双引号.

typedef struct node* Node; // 不开放给其他人使用, 只能在本文件中使用.
// typedef struct LinkedList* LinkedList; // 放入h文件, 开放给其他人使用, 可以在其它文件中使用.

struct node{
    int value1;
    double value2;
    Node next;
};

struct LinkedList{
    int len;
    Node first_node;
    Node last_node;
};

Node newNode(int value1, double value2){
    Node node = malloc(sizeof(struct node));
    node->value1 = value1;
    node->value2 = value2;
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
    // 根据两个Node的value1和value2进行比较
    // 假设此例的value2的优先级大于value1(先根据value2的大小进行排序, 若value2一致, 则根据value1的大小进行排序).
    // 如果first.value2比second.value2小, 返回 -1
    // 如果first.value2比second.value2大, 返回  1
    // 如果两者的value2相等:
            // 如果first.value1比second.value1小, 返回 -1
            // 如果first.value1比second.value1大, 返回  1
    // 如果两者的value2和value1均相等, 则返回 0
    // 类似于strcmp
    int result = 0;
    if (first->value2 < second->value2){
        result = -1;
    }else if(first->value2 > second->value2){
        result = 1;
    }else{
        if(first->value1 < second->value1){
            result = -1;
        } else if(first->value1 > second->value1){
            result = 1;
        }else{
            // 如果有三个属性需要进行排序, 则此处还有代码, 逻辑同上.
        }
    }
    return result;
}

/**
 * 假设此例的 value2 的优先级大于 value1.
 * 先根据 value2 的大小进行排序,.
 * 若 value2 一致, 则根据 value1 的大小进行排序.
 */
void appendByOrder(LinkedList list, int value1, double value2){ // 有序递增插入
    Node new_node = newNode(value1, value2);
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
                if (compareTo(new_node, pre) >= 0 && compareTo(new_node, current) <= 0){ // if(new_node->value1 >= pre->value1 && new_node->value1 <= current->value1)
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
        printf("index: %d, value1: %d, value2: %lf\n", index++, current->value1, current->value2);
        current = current->next;
    }
    printf("The length of this list: %d.\n", list->len);
}

void freeList(LinkedList list){
    if(list != NULL){
        Node current = list->first_node;
        while (current != NULL){
            Node next = current->next;
            free(current);
            current = next;
        }
        free(list);
    }
}