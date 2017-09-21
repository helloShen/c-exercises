#include "mystd.h"

static const int LIM = 10;
static int getlongline(char s[], int lim);
static void mycopy(char to[], char from[]);

int main() {
    char line[LIM];
    char maxline[LIM];
    int max = 0, len = 0;
    while ((len = getlongline(line,LIM)) != 0) {
        if (len > max) {
            max = len;
            mycopy(maxline,line);
            printf("Now, max line is: %s\n",maxline);
            printf("Now, max size = %d\n",max);
        }
    }
    printf("Max line is: %s\n",maxline);
    printf("Max size = %d\n",max);
}

/* return the length of next line. put as many character as possible to the array s */
static int getlongline(char s[], int lim) {
    char c;
    int len = 0;
    while ((c = getchar()) != EOF && c != '\n') { // loop condition is only the end of line or end of file
        // 注意！这里和答案不一样。答案给每一行都留出了回车符的位置。即使这一行很长，回车符在100个字符之后，但还是在每个返回行之后插入一个回车符。
        // 我的做法是如果回车符不够放在s[]数组里了，那就没有回车符。
        // 但无论如何，\0的位置还是要留出来的。
        if (len < lim - 1) { s[len] = c; }
        ++len;
    }
    if (c == '\n') {
        if (len < lim - 1) { s[len] = '\n'; }
        ++len;
    }
    if (len < lim) {
        s[len] = '\0';
    } else {
        s[lim-1] = '\0';
    }
    return len;
}
/* copy content in from array to to array */
static void mycopy(char to[], char from[]) {
    int i = 0;
    while ((to[i] = from[i]) != '\0') { ++i; }
}
