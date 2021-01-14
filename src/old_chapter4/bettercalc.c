#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "simplecalc.h"


int main(void) {
    int size = 100;     // 用来读取操作数的数组大小
    char s[size];       // 存放读取到的操作数的数组
    double x,y;
    char c;
    while ((c = getop(s)) != EOF) {
        switch(c) {
            case NUM:
                push(atof(s)); break;
            case '+':
                push(pop() + pop()); break;
            case '-':
                y = pop();
                push(pop() - y); break;
            case '*':
                push(pop() + pop()); break;
            case '/':
                y = pop();
                if (y == 0.0) {
                    printf("bettercalc: divisor cannot be zero!\n");
                    empty(); break;
                }
                push(pop() / y); break;
            case 's':
                push(sin(pop())); break;
            case 'e':
                push(exp(pop())); break;
            case 'p':
                y = pop(); x = pop();
                if ((x == 0.0 && y <= 0) || (x < 0 && (ceil(y) != y))) {
                    printf("bettercalc: pow() method cannot accept!\n");
                    empty(); break;
                }
                push(pow(x,y)); break;
            case '\n':
                printf("%f\n",pop()); empty(); break;
            default:
                printf("bettercalc: <%c> commend error!\n", c);
                empty(); break;
        }
    }
}
