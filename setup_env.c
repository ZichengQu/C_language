#include <stdio.h>

int main(int argc, char** argv) {
    // 通过launch.json或settings.json(cmake)的args向main函数中传参.
    printf("argc为: %d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("argv[%d]为: %s\n", i, argv[i]);
    }

    int number = 0;
    while(1) {
        printf("请输入一个数字：");  //Debug运行卡到这里时可能会报错，尽量不要在这里打断点。
        if(scanf("%d", &number) == 1) {
            printf("your input is %d\n", number);
        }
        if(number == 100) {
            break;
        }
    }

    return 0;
}