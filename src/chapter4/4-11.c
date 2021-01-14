/**
 * 练习4-11
 * 不用ungetch()函数，
 * 通过在getop()函数中加一个static变量，来实现塞回一个输入
 *
 * 因为偷懒，不再分成好多文件了
 * 4-11.o和stack.o就能运行
 */
#include <stdio.h>                              // printf()和EOF
#include <stdlib.h>                             // atof()
#include <ctype.h>                              // isdigit()
#include "calc.h"                               // stack以及传输协议

static void calcwithoutungetch(void);           // 替代原来的计算逻辑
static void enterwithoutungetch(void);          // 替代原来的enter()
static char getopwithoutungetch(char s[]);      // 替代原来的getop()
static char getchwithoutungetch(void);          // 替代原来的getch()
static void withoutungetch(char c);             // 替代原来的ungetch()

/**
 * 主入口，测试用
 */
int main(void) {
    calcwithoutungetch();
}


static const int SIZE = 100;        // 数组空间上限
static char s[SIZE];                // 用于存放每次读到的操作数
static char c;                      // getop()返回的读取到的操作符类型
static double y;                    // 减法和除法需要缓存先取出的操作数

/**
 * 计算主要逻辑
 */
static void calcwithoutungetch(void) {
    while ((c = getopwithoutungetch(s)) != EOF) {       // 改为调用重新定义的getop()函数
        switch(c) {
            case NUM:
                push(atof(s)); break;
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
                    printf("simplecalc: Zero cannot be used as divisor!\n");
                    enterwithoutungetch(); break;
                }
                push(pop() / y); break;
            case '\n':
                printf("%.8f\n", pop()); break;
            default:
                printf("simplecalc: Commend <%c> Error!\n", c);
        }
    }
}

static void enterwithoutungetch(void) {
    char c;
    while ((c = getchwithoutungetch()) != '\n') {
        if (c == EOF) { withoutungetch(c); break; }
    }
    empty();
}

/**
 * getopwithoutungetch()函数通过静态变量实现会塞一个输入
 * 模拟一个单独的文件，因为偷懒不想重新开一个文件
 * main()主入口不可访问下面的静态变量memo，所以相当于另开一个文件
 */

static char memo;
static int occupied = 0;

static char getopwithoutungetch(char s[]) {
    char c;
    int p = 0;
    // 跳过空格或制表符
    while ((s[0] = c = getchwithoutungetch()) == ' ' || c == '\t');
    s[1] = '\0';
    // 读到符号
    if (!isdigit(c)) { return c; }
    // 读到数字
    while (isdigit(c = getchwithoutungetch())) { s[++p] = c; }         // 整数部分
    if (c == '.') {
        s[++p] = c;
        while (isdigit(c = getchwithoutungetch())) { s[++p] = c; }     // 小数部分
    }
    if (c != EOF) { withoutungetch(c); }
    s[++p] = '\0';
    return NUM;
}

static char getchwithoutungetch(void) {
    if (occupied > 0) {
        occupied = 0;
        return occupied;
    } else {
        return getchar();
    }
}

static void withoutungetch(char c) {
   if (occupied == 0) {
       memo = c;
       occupied = 1;
   } else {
       printf("getopwithoutungetch: memo occupied!\n");
   }
}
