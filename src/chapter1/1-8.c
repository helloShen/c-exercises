#include "mystd.h"

int countspace();
int counttab();
int countline();
int count(char c);

int main() {
    // printf("Space number = %d\n",countspace());
    // printf("Tab number = %d\n",counttab());
    // printf("Line number = %d\n",countline());
    // printf("Space number = %d\n",count(' '));
    // printf("Tab number = %d\n",count('\t'));
    // printf("Line number = %d\n",count('\n'));
}

int countspace() {
    int count = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ' ') { ++count; }
    }
    return count;
}
int counttab() {
    int count = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\t') { ++count; }
    }
    return count;
}
int countline() {
    int count = 0;
    char c;
    while ((c = getchar()) != EOF) {
        if (c == '\n') { ++count; }
    }
    return count;
}
int count(char c) {
    int count = 0;
    char in;
    while ((in = getchar()) != EOF) {
        if (in == c) { ++count; }
    }
    return count;
}
