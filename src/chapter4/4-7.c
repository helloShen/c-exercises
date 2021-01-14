/**
 * 练习4-7
 * 将整个字符串s压回到输入中
 * 直接调用ungetch()函数，不使用自己的缓冲区
 * ungets()函数在ungets.c文件中
 * 此为测试主入口
 */
#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

void ungets(char s[]);

/** 符号打一遍，数字打10遍(塞回缓冲重新读取再打印) */
int main(void) {
    int size = 100;
    char s[size];
    double d;
    char c;
    while ((c = getop(s)) != EOF) {
        switch(c) {
            case NUM:
                d = atof(s);
                for (int i = 0; i < 10; i++) {         // 数字打印10次
                    printf("%s\t",s);
                    ungets(s);
                    getop(s);
                }
                break;
            case '\n':
                printf("\n"); break;
            default:
                printf("%c\t",c);
        }
    }
}
