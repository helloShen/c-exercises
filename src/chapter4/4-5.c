/**
 * 科学计算器。
 * 除了加减乘除，加了高级计算：
 *       sin(): 正弦函数
 *       exp(): 幂函数
 *       pow(): 乘方运算
 * 实际运算直接调用<math.h>的函数
 * 关于<math.h>的细节，详见书后附录B.4
 */
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "calc.h"


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
                    printf("science calc: divisor cannot be zero!\n");
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
                    printf("science calc: pow() method cannot accept!\n");
                    empty(); break;
                }
                push(pow(x,y)); break;
            case '\n':
                printf("%f\n",pop()); empty(); break;
            default:
                printf("science calc: <%c> commend error!\n", c);
                empty(); break;
        }
    }
}
