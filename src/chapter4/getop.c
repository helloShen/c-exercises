#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include "calc.h"

/** 服务接口在calc.h里声明 */

/**
 *  读取下一个操作数，或操作符。
 *  如果是操作数，装填在s[]数组里
 *  如果是操作符，直接通过返回值返回。
 *  暂时不支持取负数，也就是遇到 - 号，就表示减号。
 */
int getop(char s[]) {
    char c;
    while ((c = getch()) == SPACE || c == TAB) { ; }    // 跳过起始空格和制表符
    if (!isdigit(c) && c != SPOT) {                     // 不是数，就直接返回该字符
        s[0] = c; s[1] = END; return c;
    }
    int sp = 0;
    if (isdigit(c)) {                                   // 如果有整数部分，先读一波整数部分
        do {
            s[sp++] = c;
        } while ((c = getch()) && isdigit(c));
    }
    if (c == SPOT) {                                    // 如果遇到小数点，说明有小数部分
        do {
            s[sp++] = c;
        } while ((c = getch()) && isdigit(c));
    }
    if (c != EOF) { ungetch(c); }                       // 最后停在一个既不是数字也不是小数点的字符，把它塞缓存，收工
    return NUMBER;
}
