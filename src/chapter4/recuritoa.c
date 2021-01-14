/**
 * 递归itoa()函数
 * 因能独立完成服务，故单独成一个组件
 *
 * itoa()函数原型如下：
 * char *itoa( int value, char *string,int radix);
 *
 *  value：欲转换的数据。
 *  string：目标字符串的地址。
 *  radix：转换后的进制数，可以是10进制、16进制等。(省去)
 *  返回值：指向string字符串的指针
 *
 */
#include <stdlib.h> // abs()

/**
 * [递归版itoa()函数。假设string足够长，不会发生溢出。]
 * @param  value  [欲转换数字]
 * @param  string [目标字符串地址]
 * @return [告诉程序递归从哪一位开始写]
 *
 * 书上答案用一个外部变量i，和我用返回值传递从哪里开始写入，效果一样
 */
int recuritoa(int value, char *string) {
    int start = 0;
    int q = value / 10;     // quotient
    int r = value % 10;     // remainder
    if (q == 0) {           // base case
        if (r < 0) {
            string[start++] = '-';
        }
    } else {
        start = recuritoa(q, string);
    }
    r = abs(r);
    string[start++] = r + '0';
    string[start] = '\0';
    return start;
}
