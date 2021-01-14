/**
 * 最简单的带缓冲区的从标准输入读取下一个字符
 * 包含getch()和ungetch()
 * 不报错
 */
#include <stdio.h>

#define SIZE 100       // 缓冲区大小

static char buff[SIZE];       // 缓冲区
static int p;                 // 指向下一个空闲槽位

char getch(void) {
    return (p > 0)? buff[--p] : getchar();
}

void ungetch(char c) {
    if (p < SIZE) { buff[p++] = c; }
}
