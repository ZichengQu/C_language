#include <stdio.h>

/**
 * 方法级别的注释
 * @return 0: no errors.
 */
int main(){
    //单行注释
    printf("Code Annotation.\n");

    /*
    * 多行注释
    * gcc -c, compile, 编译一下检查是否有错.
    * gcc -o, output, 默认a.out
    */

    //格式化输出
    printf("%d\n", 100);
    printf("%5d\n", 100000); //向右对齐，不够5格则用空格补齐。
    printf("%-5d\n", 100); //向左对齐。
    printf("12 %% 24 = %d\n", 12 % 24); //%需要用%转置，否则其是特殊符号。
    printf("%s\n", "Code Annotation.");

    //基本数据类型

    

   
    return 0;
}