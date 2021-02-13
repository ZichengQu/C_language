#include <stdio.h>
#include <stdlib.h>

/**
 * argc: 参数个数，argument count
 * argv: 参数值，argument values
 */
int main(int argc, char* argv[]){
    printf("Output 1: argc为: %d\n", argc);
    for(int i=0; i<argc; i++){
        printf("Output 1: 第%d个参数，其值为: %s\n", i, argv[i]);
    }
}