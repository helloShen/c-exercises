#include <stdio.h>
#include <stdlib.h>
#include "bootcalc.h"

/**
 * 逆波兰计算器
 * 和书上样例的主要区别是，如果计算格式不正确，本函数可以报错
 */



/** 逆波兰计算器主要计算逻辑 */
int main() {
    int type;
    double x,y;
    char s[MAXSIZE+1];
    while ((type = getop(s)) != EOF) {
        switch (type) {
            case NUM:
                if (isFull()) { enter(); break; }
                push(atof(s)); break;
            case '+':
                if (isEmpty()) { enter(); break; }
                y = pop();
                if (isEmpty()) { enter(); break; }
                x = pop();
                push(x + y); break;
            case '-':
                if (isEmpty()) { enter(); break; }
                y = pop();
                if (isEmpty()) { enter(); break; }
                x = pop();
                push(x - y); break;
            case '*':
                if (isEmpty()) { enter(); break; }
                y = pop();
                if (isEmpty()) { enter(); break; }
                x = pop();
                push(x * y); break;
            case '/':
                if (isEmpty()) { enter(); break; }
                y = pop();
                if (y == 0) {
                    printf("calc: Divisor cannot be zero!\n");
                    enter(); break;
                }
                if (isEmpty()) { enter(); break; }
                x = pop();
                push(x / y); break;
            case '\n':
                if (isEmpty()) { enter(); break; }
                printf("\t%.8g\n",pop());
                empty(); break;
            case NUMTOOLONG:
                printf("calc: Number too long[%s]!\n",s);
                enter(); break;
            default:
                printf("calc: Unknown Commend [%s]!\n",s);
                enter(); break;
        }
    }
}

void enter(void) {
    char c;
    while ((c = getch()) != '\n') {
        if (c == EOF) { ungetch(c); break; }
    }
    empty();
}
