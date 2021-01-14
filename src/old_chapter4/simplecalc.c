#include <stdio.h>          // printf()函数需要此库
#include <stdlib.h>         // atof()函数需要此库
#include "simplecalc.h"     // simplecalc包的统一头文件

#define SIZE 100

static char s[SIZE];   // 用来从getop()获取操作数
static char c;          // getop()的返回值
static double x,y;     // 缓存弹出的两个操作数

/**
 * 主入口
 */
int main(void) {
    while ((c = getop(s)) != EOF) {
        switch(c) {
            case NUM:
                push(atof(s)); break;
            case '+':
                push(pop() + pop()); break;
            case '-':
                y = pop(); x = pop();
                push(x - y); break;
            case '*':
                push(pop() * pop()); break;
            case '/':
                y = pop();
                if (y == 0) {
                    printf("simplecalc: Zero cannot be used as divisor!\n");
                    empty(); break;
                }
                x = pop();
                push(x / y); break;
            case '\n':
                printf("%.8f\n", pop()); break;
            default:
                printf("simplecalc: Commend <%c> Error!\n", c);
        }
    }
}
