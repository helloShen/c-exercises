/**
 * 练习4-12
 * 递归版atof()函数
 */
#include <stdio.h>

/** 函数声明 */
int recuritoa(int value, char *string);

/** 测试主入口 */
int main(void) {
    int SIZE = 100;
    char s[SIZE];
    recuritoa(123, s);
    printf("%s\n", s);
    recuritoa(-123, s);
    printf("%s\n", s);
    recuritoa(0, s);
    printf("%s\n", s);
}
