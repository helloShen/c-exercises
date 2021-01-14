/**
 * 练习4-3
 * 为最简单的逆波兰计算器扩展一个取模(%)运算
 * 需要用到的组件，在simplecalac.h头文件里都声明了
 */

#include <stdio.h>          // printf()函数需要此库
#include <stdlib.h>         // atof()函数需要此库
#include <math.h>           // ceil()函数需要此库
#include "4-3.h"            // 包含calc.h，以及练习4-3的补充内容

#define SIZE 100

static char s[SIZE];   // 用来从getop()获取操作数
static char c;          // getop()的返回值
static double x,y;     // 缓存弹出的两个操作数


/**
 * 主入口
 * 对于正整数 p 和整数 a,b，定义如下运算：
 *      取模运算：a % p（或a mod p），表示a除以p的余数。
 */
int main(void) {
    while ((c = getopneg(s)) != EOF) {
        switch(c) {
            case NUM:
                push(atof(s));
                printf("get number: %f\n",atof(s));
                break;
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
                    printf("calc: Zero cannot be used as divisor!\n");
                    enter(); break;
                }
                x = pop();
                push(x / y); break;
            case '%':           // 加入处理'%'的逻辑
                y = pop();
                if (y == 0.0) {
                    printf("calc: Zero cannot be used as divisor!\n");
                    enter(); break;
                }
                push(fmod(pop(),y)); break;
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
