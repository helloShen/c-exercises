#include "mystd.h"

static int endtab(char *line, int lim);
static const int LIM = 100;
static const char TAB = '\t';
static const char LINE_END = '\n';
static const char SPACE = ' ';
static const char STR_END = '\0';

int main() {
    char line[LIM];
    int len = 0;
    while ((len = endtab(line,LIM)) != 0) {
        printf("%d:\t%s\n",len,line);
    }
}

static int endtab(char *line, int lim) {
    int len = 0;
    char c;
    while (len < lim-1 && (c = getchar()) != EOF && c != LINE_END) {
        line[len++] = c;
    }
    if (c == LINE_END && len < lim-1) { line[len++] = LINE_END; }
    line[len] = STR_END;
    return len;
}
