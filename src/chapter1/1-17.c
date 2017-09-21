#include "mystd.h"

static const int LIM = 1000;

static int mygetline(char s[], int lim);

int main() {
    char line[LIM];
    int len = 0, index = 0;
    while ((len = mygetline(line,LIM)) != 0) {
        if (len > 80) { printf("%d:\t%s\n",++index,line); }
    }
}

/* 返回下一行的长度，将其写入数组s */
static int mygetline(char s[], int lim) {
    char c;
    int cur = -1;
    while ((c = getchar()) != EOF && c != '\n') {
        if (++cur < lim-1) { s[cur] = c; }
    }
    if (c == '\n' && cur < lim-1) { s[cur++] = '\n'; }
    if (cur < lim-1) {
        s[cur] = '\0';
    } else {
        s[lim-1] = '\0';
    }
    return cur+1;
}
