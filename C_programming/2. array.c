#include <stdio.h>

void print_array(int output, int* array, int len) {
    printf("\nOutput %d:\n", output);
    for(int i = 0; i < len; i++) {  // 打印数组
        printf("%d ", array[i]);
    }
    printf("\n");
}

int main(void) {
    // 数组初始化
    int array_0[] = {1, 2, 3, 4, 5, 6, 7, 8, 9};  // 初始化，很少用。
    int array_1[5] = {1, 2, 3};                   // 直接部分初始化, 未全部初始化的部分被"随机"分配。随机：未赋值的部分是随机数(根据不同的OS, 不同优化)。
    int array_2[5] = {1, 2, 3, 4, 5};             // 直接全部初始化
    int array_3[5];                               // 声明该numbers_3数组

    for(int i = 0; i < 5; i++) {  // 逐一对numbers_3数组的每个element进行初始化
        array_3[i] = i + 2;
    }

    /* C语言中的数组不像Java或Python中的一样，它无法通过.length或len()获取其长度.
     * 1. 考虑数组的容量: MAX_LEN
     * 2. 考虑数组的元素个数: current_len
     */
    int MAX_LEN = 1024;
    int current_len = -1;  //常用-1或0，要注意index的对应.
    int array_4[MAX_LEN];
    for(int i = 0; i < MAX_LEN; i++) {  // C语言中的数组需要先初始化，再使用.
        array_4[i] = 0;
    }
    array_4[++current_len] = 2;
    array_4[++current_len] = 1;
    array_4[++current_len] = 5;
    array_4[++current_len] = 10;
    array_4[++current_len] = 7;
    printf("The length of array_4 is: %d\n", current_len + 1);
    print_array(0, array_4, current_len + 1);

    /*
    * Unsorted array: 
    *   Insert: 时间复杂度为O(1)
    *   Delete: 时间复杂度为O(n)
    * Sorted array:
    *   Insert: 时间复杂度为O(n)
    *   Delete: 时间复杂度为O(n)
    */
    // 删除unsorted array中的某一个元素.
    int deleteNum = 5;     // 待删除元素
    int deleteIndex = -1;  // 待删除元素的index
    for(int i = 0; i < current_len + 1; i++) {
        if(array_4[i] == deleteNum) {
            deleteIndex = i;  // 若待删除元素存在，则记录该index
            break;
        }
    }
    if(deleteIndex >= 0) {  // 若待删除元素存在
        int nextIndex = deleteIndex + 1;
        while(nextIndex < current_len + 1) {
            array_4[nextIndex - 1] = array_4[nextIndex];  // 依次将待删除元素后的元素，向前移动一位。
            nextIndex++;
        }
        current_len--;  // 删除了一个元素，则该array的length减少1.
    }
    print_array(1, array_4, current_len + 1);

    // Union: 两个有序数组的合并。
    int n1 = 5, n2 = 4, n3 = n1 + n2;              // Length of the array1, array2 and array3.
    int n1_index = 0, n2_index = 0, n3_index = 0;  // Current index of the array1, array2 and array3.
    int array1[] = {1, 2, 3, 4, 5};
    int array2[] = {1, 1, 2, 10};
    int array3[n3];
    while(n1_index < n1 && n2_index < n2) {  // 当两个数组均不为空时
        if(array1[n1_index] <= array2[n2_index]) {
            array3[n3_index++] = array1[n1_index++];
        } else if(array2[n2_index] < array1[n1_index]) {
            array3[n3_index++] = array2[n2_index++];
        }
    }
    while(n1_index < n1) {  // 当第一个数组不为空时
        array3[n3_index++] = array1[n1_index++];
    }
    while(n2_index < n2) {  // 当第二个数组不为空时
        array3[n3_index++] = array2[n2_index++];
    }

    print_array(2, array3, n3_index);

    // Intersection: 两个有序数组的交集。
    n1 = 5, n2 = 4;
    int n4 = n1 > n2 ? n2 : n1;  // Length of the array1, array2 and array4 (the minimum one).
    n1_index = 0, n2_index = 0;
    int n4_index = 0;  // Current index of the array1, array2 and array3.
    int array4[n4];
    while(n1_index < n1 && n2_index < n2) {  // 当两个数组均不为空时
        if(array1[n1_index] == array2[n2_index]) {
            array4[n4_index++] = array1[n1_index++];
            n2_index++;
        } else if(array1[n1_index] < array2[n2_index]) {
            n1_index++;
        } else if(array2[n2_index] < array1[n1_index]) {
            n2_index++;
        }
    }
    print_array(3, array4, n4_index);

    double array_5[10];  // double型array
    array_5[0] = -50.05;
    char array_6[10];  // char型array
    array_6[0] = 'a';

    return 0;
}