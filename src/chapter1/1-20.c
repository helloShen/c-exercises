#include "mystd.h"

static const int LIM = 100;
static const char TAB = '\t';
static const char LINE_END = '\n';
static const char STR_END = '\0';
static const char SPACE = ' ';
static const int TAB_SIZE = 8;
static int detab(char *s);

int main() {
    char line[LIM];
    int len = 0;
    while ((len = detab(line)) != 0) {
        printf("%d\t%s\n",len,line);
    }
}

/* 写进数组的版本 */
static int detab(char *s) {
    int cur = 0;
    char c;
    while ((c = getchar()) != EOF && c != LINE_END) {
        if (cur < LIM - 1) {
            if (c == TAB) {
                int nextTabEnd = (cur / TAB_SIZE + 1) * TAB_SIZE;
                while (cur < LIM-1 && cur < nextTabEnd) {
                    s[cur++] = SPACE;
                }
            } else {
                s[cur++] = c;
            }
        }
    }
    if (c == LINE_END && cur < LIM - 1) {
        s[cur++] = c;
    }
    s[cur] = STR_END;
    return cur;
}
