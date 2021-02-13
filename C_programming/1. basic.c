#include <stdio.h>
#include <stdbool.h> //为了使用bool类型.

int num = 0;      //全局动态变量(不推荐).
#define NUM 0     //全局静态变量(常量).
#define START "A" //#deifne 常量名 值

/**
 * 方法级别的注释
 * @return 0: no errors.
 */
int main(){
    // C语言运行时，内存分布：../img/array/Memory1.png  ../img/array/Memory2.png

    //单行注释
    printf("Output 1: Code Annotation.\n");

    /*
    * 多行注释
    * gcc -c, compile, 编译一下检查是否有错.
    * gcc -o, output, 默认a.out
    * gcc 是检查是否编译通过，dcc(UNSW机房特有)在gcc的基础上还会检查是否内存泄漏.
    * 若VSCode或Clion连接UNSW CSE机房debug频繁掉线，可手动dcc编译: dcc 文件名.c -o a.out
    */

    //格式化输出
    printf("Output 2: %d\n", 100);
    printf("Output 3: %5d\n", 100000);            //向右对齐, 不够5格则用空格补齐.
    printf("Output 4: %-5d\n", 100);              //向左对齐.
    printf("Output 5: 12 %% 24 = %d\n", 12 % 24); //%需要用%转置, 否则其是特殊符号.
    char *s = "Code Annotation.";
    printf("Output 6: %s\n", s);

    /*
    * 基本数据类型, char, int, float, double, short, long, unsigned, 前4种常用.
    * 1. 变量初始化.
    * 2. 变量名字有其涵义.
    * 3. 区分变量使用范围(方法级别, 代码块, 全局变量, 常量).
    * C语言不提倡使用全局动态变量(推荐在哪里使用, 在哪里定义). 若规划不好, 可能会造成内存空间的浪费. 比如在嵌入式设备中, 内存极为有限.
    */

    //char类型
    char a = 'a'; //单引号表示char. 由于是由ASCII码表示的, 所以也可直接用%d输出查看器ASCII码值.
    printf("Output 7: char=> a: %c, the digit number of char %c is %d\n", a, a, a);

    //int类型
    int num_a, num_b = 1, num_c = 2, num_d;     //可以同时声明多个变量
    printf("Output 8: int=> num: %d\n", num_b); //不同系统会优化成不同的初始值, 一定要指定初始化的值. 在UNSW的VLab不会优化, 会报错.
    const int num_e = 3;                        //const 数据类型 常量名; 使用const定义常量(不安全) ==> const定义常量是可以通过指针来进行修改的.

    //double类型
    double money = 0.0;
    printf("Output 9: double=> money: %lf\n", money);    //要对变量进行初始化.
    printf("Output 10: double=> money: %.2lf\n", money); //控制限制几位小数点.

    //bool类型, 不是原生类型, 其实就是0和1.
    bool flag1 = true; // 需提前 #include <stdbool.h>
    bool flag2 = false;
    if (flag1 == true && flag2 == false){ //或者直接判断是否等于0和1, 来代替true和false
        printf("Output 11: bool=> flag1: %d, flag2: %d\n", flag1, flag2);
    }
    else if (false){
        printf("Output 12: Here is else if.\n");
    }
    else{
        printf("Output 13: Here is else\n");
    }

    //若if-else里的代码块只有一行, 可以简写(省略大括号).
    if (flag1 == false && flag2 == false)
        printf("Output 14: bool=> flag1: %d, flag2: %d\n", flag1, flag2);
    else
        printf("Output 15: Here is else\n");
    //三目运算符 expression?true:false
    int value = (flag1 == true && flag2 == false) ? 100 : 200;
    printf("Output 16: The number of 三目运算结果: %d\n", value);
    //switch语句
    // switch(expression){
    //     case constant-expression:
    //     statement(s);
    //     break; /* 可选的 */
    //     case constant-expression:
    //     statement(s);
    //     break; /* 可选的 */

    //     /* 您可以有任意数量的 case 语句 */
    //     default: /* 可选的 */
    //     statement(s);
    // }

    //算数运算符: +, -, *, /, %, ++, --
    //关系运算符: ==, !=, >, <, >=, <=
    //逻辑运算符: &&, ||, !
    //位运算符: https://www.runoob.com/cprogramming/c-operators.html#位运算符

    //循环: for, while, do-while; break, continue及相关label.
    //从1加到100
    int total = 0;
    for (int i = 1; i <= 100; total += i++)
        ; //for(int i=1; i<=100; total = total + i, i++);
    printf("Output 17: The sum of 1 to 100: %d\n", total);

    return 0;
}