/****************************************************************
 * 书上最简单的逆波兰计算器，只有加减乘除功能
 * 假设输入公式格式正确
 ***************************************************************/

#include <stdio.h>          // printf()函数需要此库
#include <stdlib.h>         // atof()函数需要此库
#include "calc.h"           // 使用不带检查输入的简单工具包

#define SIZE 100

static char s[SIZE];    // 用来从getop()获取操作数
static char c;          // getop()的返回值
static double x,y;      // 缓存弹出的两个操作数

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
                    enter(); break;
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

void enter(void) {
    char c;
    while ((c = getch()) != '\n') {
        if (c == EOF) { ungetch(c); break; }
    }
    empty();
}
