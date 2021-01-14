#include <stdio.h>
#include "simplestack.h"        // 相当于继承自simplestack.c

extern double stackbuff[];
extern int stackp;

/**
 * stack plus
 *  1. printtop()不弹出元素的情况下打印栈顶元素
 *  2. copytop()复制栈顶元素
 *  3. exchtop()交换栈顶2个元素的值
 */
void printtop(void) {
    double d = 0.0;
    if (stackp > 0) { d = stackbuff[stackp-1]; }
    printf("top element = %f\n", d);
}

double copytop(void) {
    double d = 0.0;
    if (stackp > 0) { d = stackbuff[stackp-1]; }
    return d;
}

void exchtop(void) {
    if (stackp > 1) {
        double temp = stackbuff[stackp-1];
        stackbuff[stackp-1] = stackbuff[stackp-2];
        stackbuff[stackp-2] = temp;
    }
}
