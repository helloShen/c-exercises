#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.h"

/**
 * 可以接受[A-Z]26个字母作为可以赋值的变量，以及小写v作为一个临时寄存器。
 */
int getop46(char s[]) {
    int c;
    // 跳过起始空白字符和制表符
    while ((c = getch()) == SPACE || c == TAB) { ; }
    int sp = 0;
    int sign = 1;
    // 如果不是数字
    if (!isdigit(c) && c != SPOT) {
        // 可能是函数符号，如果没有小写字母这部分被跳过
        while (islower(c)) {
            s[sp++] = c;
            c = getch();
        }
        if (sp == 1) {          // 临时寄存器符号 v
            s[sp] = END;
            if (c != EOF) { ungetch(c); }
            return RIG;
        } else if (sp > 1) {    // sin/exp/pow函数符号
            s[sp] = END;
            if (c != EOF) { ungetch(c); }
            return FUNC;
        }
        // 可能是变量符号
        if (isupper(c)) {
            printf("Found variable %c!\n",c);
            s[sp++] = c; s[sp] = END;
            while ((c = getch()) == SPACE || c == TAB) { ; }
            if (c == EQUAL) {   // 如果变量符号后面跟的是'='等号，就是变量赋值操作
                return c;
            } else {            // 否则就是读取变量操作
                if (c != EOF) { ungetch(c); }
                return VAR;
            }
        }
        // 也可能是基本的加减乘除
        if (c == MINUS) {
            c = getch();
            if (isdigit(c)) {   // -是负号，记录下负号，接着处理数字
                s[sp++] = MINUS;
            } else {            // -是减号，当成正常的加减乘除返回
                if (c != EOF) { ungetch(c); }
                return MINUS;
            }
        } else {                // 基本的加减乘除（不包括'='等号）
            return c;
        }
    }
    // 如果是数字
    if (isdigit(c) || c == SPOT) {
        // 读整数部分
        do {
            s[sp++] = c;
        } while ((c = getch()) && isdigit(c));
        // 读小数部分，如果没有小数部分，这部分被跳过
        if (c == SPOT) {
            s[sp++] = c;
            while ((c = getch()) && isdigit(c)) {
                s[sp++] = c;
            }
        }
        if (c != EOF) { ungetch(c); }
        s[sp] = END;
        return NUMBER;
    } else {
        printf("error operator!\n");
        return -1;
    }
}
