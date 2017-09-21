#include "mystd.h"

static const char TAB = '\t';
static const char LINE_END = '\n';
static const char STR_END = '\0';
static const char SPACE = ' ';
static const int TAB_SIZE = 8;
static void detab(void);

int main() {
    detab();
}

/* 直接打印出来的版本 */
static void detab(void) {
    char c;
    int pos = 0;
    int numspace = 0;
    while ((c = getchar()) != EOF) {
        if (c == TAB) {
            numspace = TAB_SIZE - (pos % TAB_SIZE);
            // printf("pos=%d,\tspace=%d",pos,numspace);
            while (numspace-- > 0) { putchar(SPACE); ++pos; }
        } else { // here is better than the answer in the book
            putchar(c); ++pos;
            if (c == LINE_END) { pos = 0; }
        }
    }
}
