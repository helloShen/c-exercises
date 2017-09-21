#include <stdio.h>
#include <stdlib.h>

/** define的符号常量，此文件有效 */
#define MAXBUFF 100

/** 服务接口在calc.h里声明 */

/** getch静态变量，只有getch.c文件，余下部分的函数可以访问。 */
static int sp;                     // 缓冲栈指针
static char buffer[MAXBUFF];       // 缓冲栈

/** 读取下一个字符。如果缓冲区不为空，优先从缓冲区读取下一个字符。 */
int getch(void) {
    if (sp == 0) {
        return getchar();
    } else {
        return buffer[--sp];
    }
}

/** 把参数传进来的字符压进缓冲区。 */
void ungetch(int c) {
    if (sp == MAXBUFF) {
        printf("getch buffer full!");
    } else {
        buffer[sp++] = c;
    }
}
