#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "calc.h"

static int MAXVAL = 100;    // s[]缓存区的最大长度
static double op1,op2;      // 从stack弹出的两个操作数

static void calcfunc(char s[]);

int main(void) {
    calc46();
}

void calc46(void) {

    int c;                  // 从getop46()返回的操作符类型
    char s[MAXVAL];         // 装载从getop46()拿到的操作符
    double var[26];         // 缓存[A-Z]变量值
    double rigi;            // 缓存前一行的计算结果

    while ((c = getop46(s)) != EOF) {
        switch(c) {
            case NUMBER:
                push(atof(s));
                printf("Push Number %g!\n",atof(s));
                break;
            case '+':
                op2 = pop(); op1 = pop();
                push(op1 + op2);
                printf("Push Sum %g!\n",(op1 + op2));
                break;
            case '-':
                op2 = pop(); op1 = pop();
                push(op1 - op2);
                printf("Push Diff %g!\n",(op1 - op2));
                break;
            case '*':
                op2 = pop(); op1 = pop();
                push(op1 * op2);
                printf("Push Product %g!\n",(op1 * op2));
                break;
            case '/':
                op2 = pop(); op1 = pop();
                push(op1 / op2);
                printf("Push Quotient %g!\n",(op1 / op2));
                break;
            case '=':   // 把stack里第一个元素赋值给s[0]里返回的变量符号
                var[s[0]-'A'] = pop();
                printf("Assign Variable %c = %g\n",s[0],var[s[0]-'A']);
                break;
            case ENTER: // 回车，打印结果
                rigi = pop();
                printf("Result of this line = %g (memorized in rigister)\n",rigi);
                break;
            case FUNC:
                calcfunc(s);
                break;
            case VAR:   // 简单的读取变量值，把变量s[0]符号的值压到stack里
                push(var[s[0]-'A']);
                printf("Read Variable %g!\n",var[s[0]-'A']);
                break;
            case RIG:
                push(rigi);
                printf("Read Rigister %g!\n",rigi);
                break;
            default:
                printf("error: cannot recognize oprator (c = %c)!\n",c);
                break;
        }
    }
}

/** 静态方法，不对外提供服务，只有calc46()可以调用 */
static void calcfunc(char s[]) {
    if (strcmp(s,"sin") == 0) {
        push(sin(pop()));
    } else if (strcmp(s,"exp") == 0) {
        push(exp(pop()));
    } else if (strcmp(s,"pow") == 0) {
        op2 = pop(), op1 = pop();
        push(pow(op1,op2));
    } else {
        printf("Cannot recognize function %s\n",s);
    }
}
