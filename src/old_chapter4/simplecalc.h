/**
 * simplecalc.c和simplegetop.c之间的通信协议
 */
#define NUM 1


/**
 * 函数声明
 */
// getop模块
char getop(char s[]);

// getch模块
char getch(void);
void ungetch(char c);

// stack模块
// #include "simplestack.h"
#include "betterstack.h"
