#include <stdio.h>

int main(void){
    int number = 0;
    while (1) {
        printf("请输入一个数字："); //Debug运行卡到这里时可能会报错，尽量不要在这里打断点。
        if (scanf("%d", &number) == 1) {
            printf("your input is %d\n", number);
        }
        if (number == 100) {
            break;
        }
    }

    return 0;
}