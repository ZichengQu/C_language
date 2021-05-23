#include <stdio.h>
#include <string.h>

int main(void) {
    /*
     * 严格意义上来说, C语言中是没有字符串的概念的. 
     * 通常来说, C语言中, 字符串指的是char类型的数组. 
     * C语言：字符串指的是以'\0'结尾的char数组. 因此字符串是一维数组, 但一维数组不一定是字符串. 
     * \0 表示的是字符串终止符. 
     * char array[n] 等同于 char *array(赋值时，接收的是地址)
     * array[index] 等同于 *(array + index) ==> * 反应的是地址上存放的是内容.
     * 非指针型变量本身是值，用 & 取其地址. 指针型变量本身是地址，用 * 取其值.
     * int* pointer1: 指针指向某一地址, 这一地址存放的值为int类型.
     * struct LinkedList*: 指针指向某一地址, 这一地址存放"struct LinkedList"这一结构体.
     */
    char word_1[6];  // 要包含最后一个"\0"的空间.
    word_1[0] = 'H';
    word_1[1] = 'e';
    word_1[2] = 'l';
    word_1[3] = 'l';
    word_1[4] = 'o';
    word_1[5] = '\0';

    char* word_2 = "Code Annotation.";  // #include <string.h>. 获取字符串长度.

    // 两种声明string的方式，在使用上相同.
    printf("Output 1: '%s' 的内存地址为: %p\n", word_1, word_1);  // 地址：这个变量名word_1指向的就是其字符串的首字母的内存地址.
    printf("Output 2: '%s' 的内存地址为: %p\n", word_2, word_2);

    /*
    * 指向内存地址的一个指针型变量.
    * 标准写法: char * pointer
    * 但是 * 是忽略空格的, 因此也可写作 char* pointer 或 char *pointer
    */
    char* pointer;     // 声明一个指针.
    pointer = word_1;  // 为该指针赋值(值是地址).

    // 无论更改哪个, 都会更改原字符串的值.
    *(word_1 + 2)  = 'L';  // 利用地址修改值. 等同于word_1[2]
    *(pointer + 3) = 'L';  // C语言字符串中一个char是1 byte, 加1则将地址映射到下一个char.
    // 指针：指针指向的是地址, 而 * 反应的是地址上存放的是内容.
    printf("Output 3: 字符串'%s' 的第二个地址上的内容：%c\n", pointer, *(pointer + 1));

    int number01 = 1;  // 不是指针变量, 因此若取其地址, 需用 &
    printf("Output 4: 数字 number01 的值为'%d' , 其内存地址为：%p\n", number01, &number01);

    int* number02 = &number01;  // 声明并为该int*赋值. 因为指针存储的是地址, 所以通过 & 取number01的地址并为该int*赋值(值是地址).
    *number02     = 2;
    printf("Output 5: 数字 number01 的值为'%d' , 其内存地址为：%p\n", number01, &number01);  // 因为操控的是地址, 所以会同时改变number01.
    printf("Output 6: 数字 number02 的值为'%d' , 其内存地址为：%p\n", *number02, number02);

    while(strlen(word_1) > 0) {  // #include <string.h>. 获取字符串长度.
        word_1[strlen(word_1) - 1] = '\0';
        printf("Output 7: The length of '%s' is %ld.\n", word_1, strlen(word_1));
    }
}