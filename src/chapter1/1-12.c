#include "mystd.h"

#define IN 1
#define OUT 0

void solution1();
int isword(int c);

int main() {
    solution1();
}

/**
 * this solution is even better than the solution in the answer book!
 * am I right?
 * coding like talking!
 */
void solution1() {
    int c;
    int state = OUT;
    while ((c = getchar()) != EOF) {
        if (isword(c)) {
            putchar(c); state = IN;
        } else {
            if (state == IN) { putchar('\n'); state = OUT; }
        }
    }
}
int isword(int c) {
    if (c == ' ' || c == '\t' || c == '\n') {
        return 0;
    } else {
        return 1;
    }
}
