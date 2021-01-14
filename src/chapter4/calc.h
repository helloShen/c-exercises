/**********************************************************************
 * calc工具包。可用于：
 *   4-3, 4-5, 4-6
 *
 * 最简单的逆波兰计算器工具包。不检查输入格式。
 * 主要包含下面组件：
 *   1. getch.c     // 从标准输入读取一个字符（带缓冲区）
 *   2. getop.c     // 调用getch.c，读入下一个操作数，或操作符
 *   3. stack.c     // 计算用的内存
 *
 *********************************************************************/

/**
 * calc.c和getop.c之间的通信协议
 */
#define NUM     1               // getop.c告诉calc.c下一个读到的是操作数

/**
 * 函数声明
 */
//calc计算模块
void enter(void);

// getop模块
char getop(char s[]);           // 不可处理负数

// getch模块
char getch(void);
void ungetch(char c);

// stack模块 (可以直接include "simplestack.h"。这里仍然列出函数，为了保持最简）
void push(double d);
double pop(void);
void empty(void);
