/**
 * 练习4-6对calc.h的补丁
 */

/** calc.h的初始内容 */
#include "calc.h"

/** 补充的calc.c和getop.c之间的通信协议 */
#define TO      2               // 练习4-6，getop.c告诉4-6.c为某个变量赋值
#define GET     3               // 练习4-6，getop.c告诉4-6.c读取某个变量的值
#define LAST    4               // 练习4-6，getop.c告诉4-6.c读取上一次的打印值

/** 补充的getop模块的新函数 */
char getop46(char s[]);         // 4-6,可使用[a-z]二十六个变量，也可以处理负数
