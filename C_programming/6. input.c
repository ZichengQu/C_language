#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#include "5. LinkedList/5.2 orderList.h"  // 标准类库用<>, 自定义的h文件用双引号.

#define MAXSTRING 1024  // 这里暂时默认一行最大输入为1024

int readFile(char* fileName) {
    char delim[3] = " \n";  // 用空格或换行符作为分隔符，delim[3]是因为有一个空格，一个换行符和一个"\0".
    char* token;
    char line[MAXSTRING];
    FILE* fp;  // 文件指针

    if((fp = fopen(fileName, "r")) == NULL) {
        printf("file error\n");
        return 1;
    }

    int lineCount = 0;
    while(fgets(line, MAXSTRING, fp) != NULL) {  // fgets按照一行一行从文件流中去读取，把fp里的一行一行的数据(不超过MAXSTRING时遇到换行符停止，超过MAX则自动换到下一行中读取)读到line中.
        printf("> line %d] \n", ++lineCount);

        // first token
        token = strtok(line, delim);  // 这里的strtok(line, delim)和while循环的strtok(NULL, delim)的作用类似于python的split

        int count = 0;
        // iterate over the rest of the tokens
        while(token != NULL) {
            printf("    token %d) %s\n", ++count, token);
            token = strtok(NULL, delim);
        }
    }

    fclose(fp);
    return 0;
}

/**
 * @param list: 列表
 * @param fileName: 文件名
 * 将fileName中的data读入到list中. (只是个简略版，因此该list的value2暂未使用)
 * */
LinkedList readFileToList(LinkedList list, char* fileName) {
    char delim[2] = " ";  // 用空格作为分隔符，delim[2]是因为有一个空格和一个"\0".
    char* token;
    char line[MAXSTRING];
    FILE* fp;  // 文件指针

    if((fp = fopen(fileName, "r")) == NULL) {
        printf("file error\n");
        return NULL;
    }

    int lineCount = 0;
    while(fgets(line, MAXSTRING, fp) != NULL) {  // fgets按照一行一行从文件流中去读取，把fp里的一行一行的数据(不超过MAXSTRING时遇到换行符停止，超过MAX则自动换到下一行中读取)读到line中.
        printf("> line %d] \n", ++lineCount);

        // first token
        token = strtok(line, delim);  // 这里的strtok(line, delim)和while循环的strtok(NULL, delim)的作用类似于python的split

        int count = 0;
        // iterate over the rest of the tokens
        while(token != NULL) {
            printf("    token %d) %s\n", ++count, token);
            appendByOrder(list, atoi(token), "NONE");
            token = strtok(NULL, delim);  // NULL是strtok的固定用法
        }
    }

    fclose(fp);

    return list;
}

/**
 * @param argc: argument count
 * @param argv: argument values
 * argv[0]是当前被执行文件(比如out文件, 不是c文件)的路径, 因此哪怕不传参, argc至少也为1
 * 因此传入的第1个参数是argv[1]，参数2是argv[2]，参数i是argv[i]
 * */
int main(int argc, char** argv) {
    // 如果通过命令行运行是: gcc "6. input.c" ==> ./a.out 1 2 ... n 或 ./a.out string_1 string_2 ... string_n
    // 通过launch.json或settings.json(cmake)的args向main函数中传参.
    printf("argc为: %d\n", argc);
    for(int i = 0; i < argc; i++) {
        printf("argv[%d]为: %s\n", i, argv[i]);
    }

    /*
    * 命令行参数从文件中读取或将其写入到文件
    * 命令行将标准输出(不确定除了prinrf还有什么)，输出到文件 ">", 将printf的内容输出到文件中(会将该程序中输出的所有内容都放入该日志中).
    *       gcc "6. input.c" -o a.out ==> ./a.out argv_1 argv_2 ... argv_n> ../res/write_log.txt
    * 命令行从文件读入标准输入(不确定除了scanf还有什么) "<", 获取的不是argc和argv，而是通过scanf输入的值. 是按流的方式将参数输入进来.
    *       gcc "6. input.c" -o a.out ==> ./a.out < ../res/read_log.txt
    */

    // 通过标准输入 stdin
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

    // 如果是通过args传参的话，则
    // "args": ["res/readFile.txt", "res/readFileToList.txt"]
    // 不加 "../"的原因是args的执行路径为根路径(在.vscode的debug的配置文件中设置了"cwd": "${workspaceRoot}")，与a.out文件的执行路径不同.
    readFile("res/readFile.txt");  // ./a.out ../res/readFile.txt < ../res/read_log.txt

    LinkedList list = newList();                     // 一般建议在哪个方法里使用，就在哪里方法里create和free。若在方法里create，则在该main中使用后，更可能忘记free.
    readFileToList(list, "res/readFileToList.txt");  // ./a.out ../res/readFile.txt ../res/readFileToList.txt < ../res/read_log.txt
    printList(list);
    freeList(list);

    return 0;
}