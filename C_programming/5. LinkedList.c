#include <stdio.h>
#include <stdlib.h>
#include <assert.h> // 断言

typedef struct node* Node; // 将 struct node* (指针指向某一地址, 这一地址存放"struct node"这一结构体) 简写成 Node.
typedef struct LinkedList* LinkedList; // 两者名称可相同, 可不同.
// typedef int custom_name_1; // 不仅是自定义结构体可以替换名称, 基本类型也可以替换名称.
// typedef float custom_name_2;

struct node{ // 定义一个结构体, 因此node是一个自定义的数据类型.
    int value; // 4 bytes
    Node next; // 指针占 8 bytes
};

struct LinkedList{ // 这个 LinkedList 是 struct LinkedList* 中的 LinkedList, 不是简写的LinkedList.
    int len; // 该list的长度.
    Node first_node; // 该list的第一个节点.
    Node last_node; // 该list的最后一个节点.
};

Node newNode(int value){ // 创建一个node.
    Node node = malloc(sizeof(struct node)); // sizeof会申请 (4+8) 个bytes.
    node->value = value;
    node->next = NULL; // 默认为空.

    return node;
}

LinkedList newList(){ // 创建一个list. 这个LinkedList是简写的LinkedList.
    LinkedList list = malloc(sizeof(struct LinkedList)); // 这个 struct LinkedList 与 "typedef struct LinkedList* LinkedList"的两个LinkedList不同.
    list->len = 0;
    list->first_node = NULL;

    return list;
}

void append(LinkedList list, int value, int inverse, int duplicate_removal){ // 在这个list的后面追加一个node. 无需返回值, 因为是直接在地址上进行的操作.
    Node new_node = newNode(value);
    if (list->first_node == NULL){ // 如果第一个node是空的.
        list->first_node = new_node; // 则创建第一个node.
        list->last_node = list->first_node; // 因为此时该list只有一个node, 所有其最后一个node和第一个node是同一个node.
    }
    else{ // 首元素不为空.
        if(duplicate_removal){ // 去重, 相当于一个set, 但与set原理不同.
            Node current = list->first_node;
            while (current != NULL){
                if (current->value == value){
                    return;
                }
                current = current->next;
            }
        }

        if(inverse){ // 从最前面添加新节点.
            new_node->next = list->first_node;
            list->first_node = new_node;
        }else{ // 从最后面添加新节点.
            list->last_node->next = new_node; // 将新节点与list->last_node建立连接.
            list->last_node = new_node; // 更新list->last_node为new_node.
        }
        
        /*用list->last_node 可以代替下列代码.
        Node current = list->first_node;
        while (current->next != NULL){ // 找到最后一个node.
            current = current->next;
        }
        // while(current != NULL){ // 与上个while循环等价.
        //     if(current->next == NULL){
        //         break;
        //     }
        //     current = current->next;
        // }
        current->next = newNode(value); // 在最后一个node上, 追加一个新的node.
        */
       
    }
    list->len++; // 该list的length++
}

void delete(LinkedList list, int value){ // 根据value, 删除list中值为value的node.
    assert(list != NULL); // #include <assert.h> 断言这个list不为空. 若为空, 则这个程序终止.
    // if(list == NULL) return; // 这行等价于断言.
    assert(list->first_node != NULL);
    if(value == list->first_node->value){
        Node deleteNode = list->first_node;
        list->first_node = deleteNode->next; // 不需要判断list->first_node与list->last_node是否相等. 若相等, last也会被free掉. 若不相等, 就只有first会被free掉.
        free(deleteNode);
        list->len--;
    }else{
        Node pre = list->first_node;
        Node current = list->first_node->next;
        while(current != NULL){
            if(current->value == value){
                Node deleteNode = current;
                pre->next = deleteNode->next;
                free(deleteNode);
                list->len--;
                break;
            }
            pre = pre->next;
            current = current->next;
        }
    }
}

void appendByOrder(LinkedList list, int value){ // 有序递增插入
    Node new_node = newNode(value);
    if (list->first_node == NULL){ // 如果第一个node是空的.
        list->first_node = new_node; // 则创建第一个node.
        list->last_node = list->first_node; // 因为此时该list只有一个node, 所有其最后一个node和第一个node是同一个node.
    }else{
        if(value < list->first_node->value){
            new_node->next = list->first_node;
            list->first_node = new_node;
        }else if(value > list->last_node->value){
            list->last_node->next = new_node; // 将新节点与list->last_node建立连接.
            list->last_node = new_node; // 更新list->last_node为new_node.
        }else{
            Node pre = list->first_node;
            Node current = list->first_node->next;
            while (current != NULL)
            { // 当current不为空时
                if(value >= pre->value && value <= current->value){
                    break;
                }
                pre = pre->next;
                current = current->next;
            }
            pre->next = new_node;
            new_node->next = current;
        }
    }
    list->len++; // 该list的length++
}

void sort(LinkedList list){ // 对该list使用排序算法进行排序: 冒泡, 插入, 选择等等. 
    // 需要频繁操作指针, 需注意指针的bug.
}

void printList(LinkedList list, int output){ // 打印lsit
    Node current = list->first_node; // 为防止 list = list->next时, 无法重新获取原始的list.
    int index = 0;
    printf("Output %d: \t", output);
    while (current != NULL){
        // printf("Output %d: The index is %d, the value is %d.\n", output, index++, current->value);
        printf("%d ", current->value);
        current = current->next; // 为了防止找不到原始的list, 因此用一个current去承接next的赋值.
    }
    printf("\tlength: %d.\n", list->len);
}

void freeList(LinkedList list){ // 释放申请的内存.
    if(list != NULL){
        Node current = list->first_node;
        while (current != NULL){ // free掉该list中的每一个node.
            Node next = current->next;
            free(current);
            current = next;
        }
        free(list); // free掉该list的空间.
    }
}

int main(void){
    // 0 => False, 1 => True
    int inverse = 0; // 正常不需要, 这里添加inverse只是为了可以从前/后append节点.
    int duplicate_removal = 0; // 正常不需要, 这里添加duplicate_removal只是为了append时可以去重.

    LinkedList list1 = newList(); // 声明该list的地址.
    append(list1, 1, inverse, duplicate_removal); // 在其后append元素.
    append(list1, 100, inverse, duplicate_removal);
    append(list1, 100, inverse, duplicate_removal);
    append(list1, 100, inverse, duplicate_removal);
    append(list1, 10000, inverse, duplicate_removal);
    printList(list1, 1); // 打印该list的值和长度.
    freeList(list1); // 释放申请的内存

    printf("\n");

    LinkedList list2 = newList(); // 声明该list的地址.
    int len = 6;
    int values[] = {7, 8, 9, 50, 25, 98};
    for (int i = 0; i < len; i++){  // 将数组和数组长度在一起append.
        append(list2, values[i], inverse, duplicate_removal);
    }
    printList(list2, 2); // 打印该list
    delete(list2, 7); // 删除第一个Node
    printList(list2, 3);
    delete(list2, 50); // 删除中间Node
    printList(list2, 4);
    delete(list2, 98); // 删除最后一个Node
    printList(list2, 5);
    freeList(list2); // 释放申请的内存

    printf("\n");

    LinkedList list3 = newList(); // 声明该list的地址.
    appendByOrder(list3, 1); // 通过LinkedList进行有序递增插入
    appendByOrder(list3, 9);
    appendByOrder(list3, 5);
    appendByOrder(list3, 3);
    appendByOrder(list3, 8);
    printList(list3, 6); // 打印该list的值和长度.
    freeList(list3); // 释放申请的内存
}