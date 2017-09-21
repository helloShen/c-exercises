#include "mystd.h"

static int reverse(char *s);

static const int LIM = 100;

int main() {
    char line[LIM];
    int len = 0;
    while ((len = reverse(line)) != 0) {
        printf("%d\t%s",len,line);
    }
}

static int reverse(char *s) {
    char c;
    int offset = 0;
    while ((c = getchar()) != EOF && c != '\n'  && offset < LIM-1) {
        s[offset++] = c;
    }
    if (c == '\n' && offset < LIM-1) {
        s[offset++] = '\n';
    }
    s[offset] = '\0';
    int lo = 0, hi = (s[offset-1] == '\n')? offset-2 : offset-1;
    while (lo < hi) {
        char temp = s[lo];
        s[lo++] = s[hi];
        s[hi--] = temp;
    }
    return offset;
}
