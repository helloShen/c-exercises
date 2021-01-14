#include <stdio.h>      // printf(),getchar()函数需要这个库
                        // 不需要bootcalc.h头文件，因为bootgetch.c的函数完全独立

#define BUFSIZE 1       // 书上的计算器功能只需要回滚一个字符，不需要100大小的数组，1就够了。

char buf[BUFSIZE];      // 从标准输入读取的字符，暂时用不到的缓存在这里
int p;                  // 指向buf中的下一个空闲位置


/**
 * 负责调用系统函数getchar()从标准输入读取下一个字符。
 * 如果缓冲区buf不为空，则优先从缓冲区中读取下一个字符。如果buf为空，则直接从标准输入读取。
 * 好处是已经读出来的字符可以重新塞入缓冲区，来模拟塞回标准输入。
 */
int getch(void) {
    return (p > 0)? buf[--p] : getchar();
}

/**
 * 往缓冲区前一个读出的字符
 */
void ungetch(int c) {
    if (p < BUFSIZE) {
        buf[p++] = c;
    } else {
        printf("ungetch: too many characters\n");
    }
}
