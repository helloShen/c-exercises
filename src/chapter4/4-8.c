/**
 * 练习4-8
 * 最多只压回一个字符
 */
#include <stdio.h>


char getch(void);
void ungetch(char c);
void clear(void);

int main(void) {
    char c;
    clear();
    while ((c = getch()) != EOF) {
        if (c == '1') {
            for (int i = 1; i < 10; i++) {
                printf("%c\t",c);
                ungetch(c);
                c = getch();
            }
        } else if (c == '\n'){
            printf("%c",c);
        } else {
            printf("%c\t",c);
        }
    }
}


static char memo;

char getch(void) {
    char c = (memo == 0)? getchar() : memo;
    memo = 0;
    return c;
}

void ungetch(char c) {
    if (memo != 0) {
        printf("ungetch err: memo is full!\nt");
    } else {
        memo = c;
    }
}

void clear(void) {
    memo = 0;
}
