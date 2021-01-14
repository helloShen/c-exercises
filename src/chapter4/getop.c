#include <stdio.h>          // EOF依赖此库
#include <ctype.h>          // isdigit()函数需要这个库
#include "calc.h"           // 依赖getch.c中的函数

/**
 * 最简单的从标准输入读取下一个操作数或操作符
 * 不报错
 */
char getop(char s[]) {
    char c;
    int p = 0;
    // 跳过空格或制表符
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    // 读到符号
    if (!isdigit(c)) { return c; }
    // 读到数字
    while (isdigit(c = getch())) { s[++p] = c; }         // 整数部分
    if (c == '.') {
        s[++p] = c;
        while (isdigit(c = getch())) { s[++p] = c; }     // 小数部分
    }
    if (c != EOF) { ungetch(c); }
    s[++p] = '\0';
    return NUM;
}

/**
 * 练习4-3，读取下一个操作数(可以是负数)
 */
char getopneg(char s[]) {
    char c;
    int p = 0;
    // 跳过空格或制表符
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    // 读到符号
    if (!isdigit(c)) {
        if (c == '-') {
            if (!isdigit(c = getch())) {                  // 减号返回
                if (c != EOF) { ungetch(c); }
                return '-';
            } else {                                      // 负数继续取数字
                s[++p] = c;
            }
        } else {
            return c;
        }
    }
    // 读到数字
    while (isdigit(c = getch())) { s[++p] = c; }         // 整数部分
    if (c == '.') {
        s[++p] = c;
        while (isdigit(c = getch())) { s[++p] = c; }     // 小数部分
    }
    if (c != EOF) { ungetch(c); }
    s[++p] = '\0';
    return NUM;
}
