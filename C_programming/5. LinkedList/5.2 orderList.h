// typedef struct node* Node; // 不开放给其他人使用, 只能在其C文件中使用.
typedef struct LinkedList* LinkedList;  // 将LinkedList开放给其它人使用，但只是开放使用权限，查看不到LinkedList结构体里的细节.

// struct node { // 最好不要将结构体暴漏给第三方. 因为C语言是操作内存的, 最好不要让第三方知道结构体的定义, 防止其修改内存地址. 比如知道了value的地址，可以强制更改其地址上的值.
//     double value;
//     char* string;
//     Node next;
// };

// struct LinkedList{
//     int len;
//     Node first_node;
//     Node last_node;
// };

/**
 * 创建一个Node
 */
// Node newNode(); // 不开放给其它人使用, 只能在orderList.c里面调用

/**
 * 创建一个list
 */
LinkedList newList();  // 开放给其它人使用

/**
 * 对两个node的value1和value2(优先)的大小进行比较
 */
// int compareTo(Node first, Node second); // 不开放给其它人使用, 只能在orderList.c里面调用

/**
 * 递增插入
 * 优先按照value2的大小进行递增插入
 * 其次按照value1的大小进行递增插入(若value2相等时)
 * @param list LinkedList型的一个list
 * @param value1 
 * @param value2
 */
void appendByOrder(LinkedList list, double value, char* string);

/**
 * 打印list
 */
void printList(LinkedList list);

/**
 * 释放list的空间
 */
void freeList(LinkedList list);