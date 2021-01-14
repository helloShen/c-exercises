#include <stdio.h>
#include <stdlib.h>
#include "stack.h"

/**
 * 服务接口在calc.h里声明
 *      void push(double num);
 *      double pop(void);
 */

/**
 * 容器在stack.h里声明，要和stackexp.c共享
 */

/** 把传进来的参数num压入栈 */
void push(double num) {
    if (sp < MAXVAL) {
        val[sp++] = num;
        // printf("push %f in stack!\n",num);
    } else {
        printf("Stack is full! Cannot push %g!\n",num);
    }
}

/** 弹出当前栈顶元素。若栈为空，则返回0.0，且报错. */
double pop(void) {
    if (sp > 0) {
        // printf("pop %f from stack!\n",val[sp-1]);
        return val[--sp];
    } else {
        printf("Stack is empty! Cannot pop number!\n");
        return 0.0;
    }
}
