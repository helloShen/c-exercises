#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include "calc.h"

/**
 * 调用sin(),exp(),pow()的符号
 * 只有getop45需要知道这部分信息
 */
static const char SINOP[] = "sin";
static const char EXPOP[] = "exp";
static const char POWOP[] = "pow";

/** 服务接口在calc.h里声明 */

/**
 *  读取下一个操作数，或操作符。
 *  如果是操作数，装填在s[]数组里
 *  如果是操作符，直接通过返回值返回。
 *  支持取负数，遇到 - 号，会判断是负号还是减号。
 *  能识别SIN,EXP,POW操作符
 */
int getop45(char s[]) {
    char c;
    while ((c = getch()) == SPACE || c == TAB) { ; }    // 跳过起始空格和制表符
    int sp = 0;
    if (!isdigit(c) && c != SPOT && c != MINUS) {       // 不是数，要取完整，检查是不是函数调用
        do {
            s[sp++] = tolower(c);
        } while ((c = getch()) && isalpha(c));
        s[sp] = END;
        if (c != EOF) { ungetch(c); }
        // printf("I found operator: %s\n",s);
        if (strcmp(s,SINOP) == 0) {                          // sin
            return SIN;
        } else if (strcmp(s,EXPOP) == 0) {                   // exp
            return EXP;
        } else if (strcmp(s,POWOP) == 0) {                   // pow
            return POW;
        } else {                                                 // 正常的+-*/
            // printf("Find operator %c\n",s[sp-1]);
            return s[sp-1];
        }
    }
    if (c == MINUS) {
        if (isdigit(c = getch()) || c == SPOT) {       // 负号
            s[sp++] = MINUS;
        } else {                                        // 减号
            if (c != EOF) { ungetch(c); }
            s[sp++] = MINUS; s[sp] = END;
            // printf("Find operator %c\n",s[sp-1]);
            return MINUS;
        }
    }
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
