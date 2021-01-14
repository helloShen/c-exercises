/**
 * 递归打印十进制整数n
 */
#include <stdio.h>

void printd(int n);

/** 测试 */
int main(void) {
    printd(123);
    printf("\t[answer=123]\n");
    printd(-123);
    printf("\t[answer=-123]\n");
    printd(0);
    printf("\t[answer=0]\n");
}

/** 递归打印十进制整数n */
void printd(int n) {
    if (n < 0) {            // 处理负数
        putchar('-');
        n = -n;
    }
    int m = n / 10;
    if (m) {
        printd(m);
    }
    putchar(n % 10 + '0');
}
