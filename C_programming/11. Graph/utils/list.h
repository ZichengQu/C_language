#include <assert.h>  // 断言
#include <stdbool.h>
#include <stdio.h>
#include <stdlib.h>

// typedef struct node* Node;              // 将 struct node* (指针指向某一地址, 这一地址存放"struct node"这一结构体) 简写成 Node.
typedef struct LinkedList* LinkedList;  // 两者名称可相同, 可不同.
// typedef int custom_name_1; // 不仅是自定义结构体可以替换名称, 基本类型也可以替换名称.
// typedef float custom_name_2;

// struct node {   // 定义一个结构体, 因此node是一个自定义的数据类型.
//     int value;  // 4 bytes
//     Node next;  // 指针占 8 bytes
// };

// struct LinkedList {   // 这个 LinkedList 是 struct LinkedList* 中的 LinkedList, 不是简写的LinkedList.
//     int len;          // 该list的长度.
//     Node first_node;  // 该list的第一个节点.
//     Node last_node;   // 该list的最后一个节点.
// };

/**
 * 创建一个node.
 */
// Node newNode(int value);

/**
 * 创建一个list. 这个LinkedList是简写的LinkedList.
 */
LinkedList newList();

/**
 * 在这个list的后面追加一个node. 无需返回值, 因为是直接在地址上进行的操作.
 * @param inverse: 从最前面添加新节点
 * @param duplicate_removal: 去重, 相当于一个set, 但与set原理不同
 */
void append(LinkedList list, int value, int inverse, int duplicate_removal);

/**
 * 根据value, 删除list中值为value的node.
 */
void delete(LinkedList list, int value);

/**
 * 对比两个Node的value的大小
 * 如果第一个比第二个小, 返回 -1
 * 如果第一个比第二个大, 返回  1
 * 如果两者相等, 返回 0
 * 类似于strcmp
 */
// int compareTo(Node first, Node second);

/**
 * 有序递增插入
 */
void appendByOrder(LinkedList list, int value);

/**
 * 对该list使用排序算法进行排序: 冒泡, 插入, 选择等等.
 * 需要频繁操作指针, 需注意指针的bug.
 */
void sort(LinkedList list);

/**
 * 判断该list中是否存在value
 */
bool valueIsExist(LinkedList list, int value);

/**
 * 判断该List是否为空
 */
bool isEmptyList(LinkedList list);

/**
 * 打印lsit
 */
void printList(LinkedList list);

/**
 * 释放申请的内存.
 */
void freeList(LinkedList list);