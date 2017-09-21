#include "mystd.h"

static int mygetline(char s[], int lim);
static int stdgetline(char s[], int lim);
static int getlongline(char s[], int lim);
static void testmygetline(int lim);
static void teststdgetline(int lim);
static void mycopy(char to[], char from[]);
static void stdcopy(char to[], char from[]);

typedef int bool;
static const int T = 1;
static const int F = 0;

/* 打印最长的输入行 */
int main() {
    // testmygetline(10);
    // teststdgetline(10);
    int lim = 10;
    char s[lim];
    char max[lim];
    int maxlen = 0;
    int len = 0;
    int thislen = 0;
    bool isnewline = T; // 下面要读入的内容是不是新的一行
    while ((thislen = getlongline(s,lim)) != 0) {
        // printf("Line: %s\n",s);
        // printf("Length = %d\n",thislen);
        if (thislen < 0) {
            len -= thislen;
        } else {
            len = thislen;
        }
        if (len > maxlen) {
            maxlen = len;
            if (isnewline) { mycopy(max,s); }
        }
        // printf("Max size: %d\n",maxlen);
        // printf("Max line = %s\n",max);
        if (thislen < 0) { // 更新下一行读入的是不是新的一行
            isnewline = F;
        } else {
            isnewline = T;
        }
    }
    printf("Max length = %d\n",maxlen);
    printf("Longest line is: %s\n",max);
}

/*
 * 这一题的getline()函数。第一版。没有1-16-2.c的第二版解决方法好。
 * 将下一行读入到s中，并返回其长度。
 * 如果这一行长度超过了s的长度，返回长度的相反数（负值）。
 */
static int getlongline(char s[], int lim) {
    char c;
    int cur = 0;
    int reachend = 0;
    while (cur < lim - 1 && (c = getchar()) != EOF && c != '\n') {
        s[cur++] = c;
    }
    if (c == '\n') { // 读完一行
        s[cur++] = c;
        reachend = 1;
    }
    s[cur] = '\0';
    if (reachend) {
        return cur;
    } else {
        return (0-cur);
    }
}


/* 将下一行读入到s中，并返回其长度（不包含末尾\0）。返回0如果到达文件末尾。 */
static int stdgetline(char s[], int lim) {
    int c, i;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; ++i) {
        s[i] = c;
    }
    if (c == '\n') {
        s[i] = c;
        ++i;
    }
    s[i] = '\0';
    return i;
}
/* 我刚开始的getline()函数的思路 */
static int mygetline(char s[], int lim) {
    char c;
    int cur = 0;
    while (cur < lim - 1 && ((c = getchar()) != EOF) && c != '\n') { // 一直到倒数第二格，除了换行符`\n`，读到什么都写
        s[cur++] = c;
    }
    if (c == '\n') { s[cur++] = c; } // stop because reach the end of line
    s[cur] = '\0';
    return cur; // 读到EOF不用着急返回0,还是正常返回。下一次调用mygetline()会直接返回0.
}
/* 测试anothergetline()函数 */
static void testmygetline(int lim) {
    char s[lim];
    int len = 0;
    while ((len = mygetline(s,lim)) != 0) {
        printf("%s [length=%d]\n",s,len);
    }
    printf("%s\n",s);
}
/* 测试mygetline()函数 */
static void teststdgetline(int lim) {
    char s[lim];
    int len = 0;
    while ((len = stdgetline(s,lim)) != 0) {
        printf("%s\n",s);
    }
    printf("%s\n",s);
}

/* 将from复制到to。假设to足够大 */
static void stdcopy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') { i++; }
}
static void mycopy(char to[], char from[]) {
    int cur = 0;
    char c;
    while ((c = from[cur]) != '\0') {
        to[cur++] = c;
    }
    to[cur] = '\0';
}
