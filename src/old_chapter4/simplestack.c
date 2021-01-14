/**
 * 最简单的stack功能，只有push()和pop()
 * 也不报错
 */
#define SIZE 100             // 栈区间大小

// 两个全局变量，可被betterstack利用
double stackbuff[SIZE];     // 栈
int stackp;                 // 指向缓冲区下一个空闲槽位

void push(double d) {
    if (stackp < SIZE) { stackbuff[stackp++] = d; }
}

double pop(void) {
    return (stackp > 0)? stackbuff[--stackp] : 0.0;
}

void empty(void) {
    stackp = 0;
}
