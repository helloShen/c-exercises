#include <stdio.h>          // EOF
#include <stdlib.h>         // isdigit()函数
#include <ctype.h>          // isdigit(), isalpha()
#include "4-6.h"            // 包含了calc.h包，以及4-6的扩展

/**
 * 练习4-6，读取下一个操作数(可以是负数)。
 * 可以存取变量。
 */
char getop46(char s[]) {
    char c;
    int p = 0;
    // 跳过空格或制表符
    while ((s[0] = c = getch()) == ' ' || c == '\t');
    s[1] = '\0';
    // 读到符号，或字母
    if (!isdigit(c)) {
        if (c == '-') {
            if (!isdigit(c = getch())) {                  // 减号返回
                if (c != EOF) { ungetch(c); }
                return '-';
            } else {                                      // 负数继续取数字
                s[++p] = c;
            }
        } else if (c == '>') {                            // 为一个变量赋值
            s[0] = getch();
            return TO;
        } else if (c == '<') {                            // 读取上一次的打印值
            return LAST;
        } else if (isalpha(c)) {                          // 读取某个变量
            return GET;
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
