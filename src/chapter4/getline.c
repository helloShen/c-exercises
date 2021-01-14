/**
 * 练习4-10
 * readline()函数读取完整的一行
 */
#include <stdio.h>
#include <ctype.h>
#include "4-10.h"

static const int SIZE = 1000;
static char s[SIZE];
static int p;

/** 读取的信息储存在s[]数组内。函数返回值为读取行的长度 */
int readline(void) {
    int len = 0;
    char c;
    while ((c = getchar()) != '\n') {
        if (c == EOF) { break; }
        s[len++] = c;
    }
    s[len] = '\0';
    p = 0;
    return len;
}

/** 从储存的s[]中读取下一个操作数，返回值为读取到操作符的种类 */
int getopfromline(char res[]) {
    char c;
    int i = 0;
    while ((c = s[p++]) == ' ' || c == '\t');               // 跳过空格和制表符
    if (c != '\0') { res[i++] = c; }
    res[i] = '\0';
    if (isdigit(c)) {
        while (isdigit(c = s[p++])) { res[i++] = c; }       // 整数部分
        if (c == '.') {
            res[i++] = '.';
            while (isdigit(c = s[p++])) { res[i++] = c; }   // 小数部分
        }
        p--;
        return NUM;
    }
    return c;
}
