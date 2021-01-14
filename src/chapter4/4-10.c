/****************************************************************
 * 只用getline，不用getch()和ungetch()
 ***************************************************************/
#include <stdio.h>              // printf()函数需要此库
#include <stdlib.h>             // atof()函数需要此库
#include "4-10.h"               // getline()和getopfromline()


static const int SIZE = 1000;
static char op[SIZE];           // 用来从getop()获取操作数
static char c;                  // getop()的返回值
static double y;                // 缓存弹出的两个操作数

/**
 * 主入口
 */
int main(void) {
    int len;
    while ((len = readline()) > 0) {
        while ((c = getopfromline(op)) != '\0') {
            switch(c) {
                case NUM:
                    push(atof(op)); break;
                case '+':
                    push(pop() + pop()); break;
                case '-':
                    y = pop();
                    push(pop() - y); break;
                case '*':
                    push(pop() * pop()); break;
                case '/':
                    y = pop();
                    if (y == 0) {
                        printf("4-10 err: Zero cannot be used as divisor!\n");
                        break;
                    }
                    push(pop() / y); break;
                default:
                    printf("4-10 err: Commend <%c> Error!\n", c);
            }
        }
        printf("%.8f\n", pop());
    }
}
