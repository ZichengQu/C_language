#include "5.2 orderList.h"  // 标准类库用<>, 自定义的h文件用双引号.

/**
 * The command to run this main:
 * gcc -g "C_programming/5. LinkedList/5.2 orderList.h" "C_programming/5. LinkedList/5.2 orderList.c" "C_programming/5. LinkedList/5.2 orderList_main.c" -o a.out
 */
int main(void) {
    LinkedList list = newList();  // 声明该list的地址.
    // 无法在此main文件中调用list的属性. 在h文件中未开放struct LinkedList(未在h文件中写出), 因此不知道是如何实现的.
    appendByOrder(list, 6.6, "BB");  // 通过LinkedList进行有序递增插入(先判断value1, 再判断value2).
    appendByOrder(list, 5.5, "AA");
    appendByOrder(list, 6.6, "EE");
    appendByOrder(list, 9.8, "FF");
    appendByOrder(list, 6.6, "GG");
    appendByOrder(list, 10.9, "CC");
    appendByOrder(list, 6.6, "DD");

    printList(list);
    freeList(list);

    return 0;
}