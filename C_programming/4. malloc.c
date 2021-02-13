#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/**
 * argc: 参数个数, argument count
 * argv: 参数值, argument values
 * ./a.out 1 2 3 4 5 6 7 8 9 10 10 9 8 7 6 5 4 3 2 1 0
 * ./a.out hello world
 * ./a.out hello hello
 */
int main(int argc, char *argv[]){

    printf("Output 1: argc为: %d\n", argc);
    for (int i = 0; i < argc; i++){
        printf("Output 1: 第%d个参数, 其值为: %s\n", i, argv[i]); // 第0个参数是 .out文件名, 第一个才开始是参数.
    }

    // int *numbers = malloc(sizeof(int) * (argc - 1)); // 在heap区分配了一块内存.
    // for (int i = 1; i < argc; i++){
    //     numbers[i - 1] = atoi(argv[i]); // atoi强转成数字. 等效于 *(numbers + i - 1) = argv[i];
    // }

    // printf("\nOutput %d: 该numbers数组为:\n", 2);
    // for (int i = 0; i < argc - 1; i++){ // 打印数组
    //     printf("%d ", numbers[i]);
    // }
    // printf("\n");

    // free(numbers); // 手动申请的内存, 要手动去释放.

    char *first_word = malloc(sizeof(char) * strlen(argv[1] + 1));  // 第一个参数的下标为1, 不是0. 加1是因为要把字符串中 \0 的位置加上.
    char *second_word = malloc(sizeof(char) * strlen(argv[2] + 1)); // 要小心malloc的内存申请和释放问题.
    // first_word = argv[1]; // 如果这样, 其malloc的内存就没用了.
    // second_word = argv[2]; // 因为char* 指针指向了argv的stack区.

    strcpy(first_word, argv[1]); // 利用strcpy, 将argv的值, 拷贝过来, 放到malloc所申请的heap区的内存中.
    strcpy(second_word, argv[2]); // 若second_word的空间比argv[2]小, 则可能会造成bug.

    // for(int i=0; i<strlen(argv[1]); i++){ // strcpy 等价于这个for循环的作用.
    //     first_word[i] = argv[1][i];
    // }
    printf("Output 3: first_word is '%s', and second_word is '%s'\n", first_word, second_word);

    // strcmp返回0则表示这两个字符串相等.
    if (strcmp(first_word, second_word) == 0){ // 若first_word == second_word, 则表示的是判断地址是否相等.
        printf("Output 4: first_word (%s)与second_word (%s)相等.'\n", first_word, second_word);
    }
    else{
        printf("Output 4: first_word (%s) 与 second_word (%s) 不相等.'\n", first_word, second_word);
    }

    free(first_word);
    free(second_word);

    return 0;
}