/**
 * 可以存储和调用[a-z]26个变量
 * 还有一个变量last存储上一次输出的变量
 * 虽然和答案书上的处理方法不一样，但这样也可以，效果是一样的
 */
#include <stdio.h>                  // printf()
#include <stdlib.h>                 // atof()
#include "4-6.h"                    // 包含clac.h包，以及练习4-6的追加补丁

int main(void) {
    int size = 100;                 // 操作数存储空间s的大小
    char s[size];                   // 存放getop()读取的下一个操作数
    char c;                         // 读取的下一操作符的种类
    double y;                       // 计算用到的2个缓存位
    // 4-6用到内存区
    double vars[26];                // 存放[a-z]26个变量
    double last;                    // 存放最近一个打印的值
    while ((c = getop46(s)) != EOF) {
        switch(c) {
            case NUM:
                push(atof(s)); break;
            case '+':
                push(pop() + pop()); break;
            case '-':
                y = pop();
                push(pop() - y); break;
            case '*':
                push(pop() * pop()); break;
            case '/':
                y = pop();
                if (y == 0.0) {
                    printf("4-6 err: divisor cannot be zero!\n");
                    enter(); break;
                }
                push(pop() / y); break;
            case '\n':
                last = pop();
                printf("%f\n", last); break;
            case TO:                                        // 为某个变量赋值
                vars[s[0] - 'a'] = pop(); break;
            case GET:                                       // 读取某个变量的值，并压入栈
                push(vars[s[0] - 'a']); break;
            case LAST:                                      // 读取上一次的打印值，并压入栈
                push(last); break;
            default:
                printf("4-6 err: commend not correct!\n");
                enter(); break;
        }
    }
}

/**
 * 跳过此行，转到下一行的开头
 * 同时，清空stack
 */
void enter(void) {
    char c;
    while ((c = getch()) != '\n') {
        if (c == EOF) { empty(); return; }
    }
    empty();
}
