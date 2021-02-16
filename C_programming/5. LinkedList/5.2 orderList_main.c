
#include "5.2 orderList.h" // 标准类库用<>, 自定义的h文件用双引号.

/**
 * The command to run this main:
 * gcc -g "C_programming/5. LinkedList/5.2 orderList.h" "C_programming/5. LinkedList/5.2 orderList.c" "C_programming/5. LinkedList/5.2 orderList_main.c" -o a.out
 */
int main(void){
    LinkedList list = newList(); // 声明该list的地址. 
    // 无法在此main文件中调用list的属性. 在h文件中未开放struct LinkedList(未在h文件中写出), 因此不知道是如何实现的.
    appendByOrder(list, 1, 6.6); // 通过LinkedList进行有序递增插入(先判断value2, 再判断value1).
    appendByOrder(list, 9, 5.5);
    appendByOrder(list, 5, 6.6);
    appendByOrder(list, 3, 9.8);
    appendByOrder(list, 5, 6.6);
    appendByOrder(list, 3, 10.9);
    appendByOrder(list, 8, 6.6);
    
    printList(list);
    freeList(list);

    return 0;
}