#define MAXVAL 100      // 栈最大深度

/**
 * stack.c和stackexp.c共享栈内存
 */
int sp;                 // 栈当前元素指针
double val[MAXVAL];     // 栈容器
