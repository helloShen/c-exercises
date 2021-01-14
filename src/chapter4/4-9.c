/**
 * 练习4-9
 * 可以压回EOF
 *
 */
#include <stdio.h>


char getch(void);
void ungetch(char c);
void clear(void);

int main(void) {
    int i;
    clear();
    while ((i = getch()) != EOF) {
        if (i == '1') {
            for (int j = 0; j < 10; j++) {
                printf("%c\t",i);
                ungetch(i);
                i = getch();
            }
        } else if (i == '\n'){
            printf("%c",i);
        } else {
            printf("%c\t",i);
        }
    }
    if (i == EOF) {
        for (int j = 0; j < 10; j++) {
            printf((j == 9)? "%d" : "%d\t",i);
            ungetch(EOF);
            i = getch();
        }
        printf("\n");
    }
}


/** 关键就是把memo声明称整数型。因为EOF在<stdio.h>中的定义是-1 */
static int memo;

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
