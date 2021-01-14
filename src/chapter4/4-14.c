/**
 * 练习4-14
 * 定义宏swap(x,y)，交换x,y两个参数
 * swap1()和swap2()两种写法都可以。
 */
#include <stdio.h>

/** 第一种写法，要么不换行 */
#define swap1(t, x, y) { t _z; _z = x; x = y; y = _z; }

/** 第二种写法，要换行的话，行末要加反斜杠'\' */
#define swap2(t, x, y) { t _z;   \
                         _z = x; \
                         x = y;  \
                         y = _z;}

int main(void) {
    int x = 10, y = 5;
    printf("x=%d,\ty=%d\n",x,y);
    swap1(int,x,y);
    printf("x=%d,\ty=%d\n",x,y);
    swap2(int,x,y);
    printf("x=%d,\ty=%d\n",x,y);
}
