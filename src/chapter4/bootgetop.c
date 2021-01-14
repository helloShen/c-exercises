#include <stdio.h>      // EOF需要这个库
#include <ctype.h>      // isdigit()需要这个库
#include "bootcalc.h"

// 只需要本地知道
#define SPACE ' '
#define TAB '\t'
#define DOT '.'
#define END '\0'

/**
 * 本函数只负责读取，不负责识别符号
 * 如果是数字，在s[]数组里填充完整数字，并返回NUM
 * 否则直接返回读到的那个符号(包括EOF)
 */
int getop(char s[]) {
    int i;          // 指向下一个空闲槽位
    char c;         // 读到的字符

    // 跳过空格或制表符，在s[0]记录之后的第一个字符
    while ((s[0] = c = getch()) == SPACE || c == TAB);
    s[1] = END;

    // 如果是符号，直接返回符号（包括EOF）
    if (!isdigit(c)) { return c; }
    // 是数字，收集完整数字
    i = 0;
    // 整数部分
    while (++i < MAXSIZE && isdigit(s[i] = c = getch()));
    if (i == MAXSIZE) {
        if (isdigit(c = getch()) || c == DOT) {    // 操作数过长
            return NUMTOOLONG;
        } else {                                     // 正好满
            s[i] = END;
            if (c != EOF) { ungetch(c); }
            return NUM;
        }
    }
    // 小数部分
    if (c == DOT) {
        while (++i < MAXSIZE && isdigit(s[i] = c = getch()));
    }
    if (i == MAXSIZE && isdigit(c = getch())) {                 // 操作数过长
        return NUMTOOLONG;
    } else {                                                      // 正好满
        s[i] = END;
        if (c != EOF) { ungetch(c); }
        return NUM;
    }
}
