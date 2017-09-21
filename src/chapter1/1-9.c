#include "mystd.h"

void solution1();
void solution2();
void solution3();
void solution4();
void donothing();

int main() {
    // donothing();
    // solution();
    // solution2();
    // solution3();
    solution4();
}

void donothing() {
    char c;
    while ((c = getchar()) != EOF) {
        putchar(c);
    }
    putchar('\n');
}
/** solution4 is inspired by the answer book */
void solution4() {
    char c;
    char lastc = 'a';
    while ((c = getchar()) != EOF) {
        if (c == ' ' && lastc == ' ') { continue; }
        putchar(c);
        lastc = c;
    }
}
/**
 * best solution in all 4 solutions
 * offical solution in the answer book
 */
void solution3() {
    char c;
    char lastc = 'a';
    while ((c = getchar()) != EOF) {
        if (c != ' ' || lastc != ' ') {
            putchar(c);
        }
        lastc = c;
    }
}
/** solution2 is better than solution1 */
void solution2() {
    char c;
    int haveSpace = 0;
    while ((c = getchar()) != EOF) {
        if (haveSpace && c == ' ') {
            continue;
        } else if (haveSpace) {
            haveSpace = 0;
        }
        if (!haveSpace && c == ' ') { haveSpace = 1; }
        printf("%1c",c);
    }
    printf("\n");
}
void solution1() {
    char c;
    int haveSpace = 0;
    while ((c = getchar()) != EOF) {
        if (haveSpace) {
            if (c == ' ') {
                continue;
            } else {
                haveSpace = 0;
            }
        }
        if (!haveSpace && c == ' ') { haveSpace = 1; }
        printf("%1c",c);
    }
    printf("\n");
}
