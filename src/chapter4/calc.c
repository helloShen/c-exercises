#include <stdio.h>
#include <stdlib.h>
#include "calc.h"

/** define的字符常量，此文件范围都有效 */
#define MAXOP 100   // 交给getop()函数去装下一个操作数的数组s的最大长度

/** 服务接口在calc.h里声明 */

/**
 * 主入口直接调用calc()服务
 * 编译的时候有其他主入口的时候，注销这个入口
 */
/*
int main(void) {
    calc();
}
*/

/**
 * 计算一个算术式的结果
 * 每一行记录是一个算数式（有回车就算一行）
 */
void calc(void) {
    /* 局部变量只声明，不初始化 */
    int type;       // getop()返回的取到的下一个操作符的类型
    double op1,op2; // 遇到 "+-*/" 操作符，用来缓存从Stack里弹出的两个操作数
    char s[MAXOP];  // 交给getop()取下一个操作符的数组容器

    while ((type = getop(s)) != EOF) {
        switch(type) {
            case NUMBER:
                push(atof(s));
                break;
            case '+':
                op2 = pop(); op1 = pop();
                push(op1 + op2);
                break;
            case '-':
                op2 = pop(); op1 = pop();
                push(op1 - op2);
                break;
            case '*':
                op2 = pop(); op1 = pop();
                push(op1 * op2);
                break;
            case '/':
                op2 = pop(); op1 = pop();
                if (op2 != 0.0) {
                    push(op1 / op2);
                } else {
                    printf("error: zero divisor\n");
                }
                break;
            case '\n':
                printf("\t%.8g\n",pop());
                break;
            default:
                printf("error: unknown command %s\n",s);
        }
    }
}
