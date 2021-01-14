#include <stdio.h>      // printf(),getchar()需要此库
                        // 不需要bootcalc.h头文件，因为bootgetch.c的函数完全独立

static const int STACKSIZE = 10;        // stack默认容量

static double stack[STACKSIZE];         // stack内存空间
static int p = 0;                       // 指向下一个空闲槽位

/** 检查栈是否已满 */
int isFull() {
    int res = (p >= STACKSIZE)? 1 : 0;
    if (res) { printf("stack: calc stack is full. check your commend.\n"); }
    return res;
}
/** 压入操作数。之前必须调用isFull()函数检查 */
void push(double d) {
    stack[p++] = d;
}


/** 检查栈是否为空 */
int isEmpty() {
    int res = (p == 0)? 1 : 0;
    if (res) { printf("stack: calc stack is empty. check your commend.\n"); }
    return res;
}
/** 弹出操作数。之前必须调用isEmpty()函数检查 */
double pop(void) {
    return stack[--p];
}


// 清空栈
void empty(void) {
    p = 0;
}
