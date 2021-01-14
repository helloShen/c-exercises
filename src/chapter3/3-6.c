#include <stdio.h>

static void itoa(int n, char *s, int min);
static void reverse(char *s);

int main(void) {
    char s[15];
    int x = -2147483648;
    itoa(x,s,11);
    printf("%d \t->\t %s\n",x,s);

    int y = 1234567;
    itoa(y,s,11);
    printf("%d \t->\t %s\n",y,s);
}

/**
 * 把数字n转换成字符串，存在数组s中。如果长度小于min，左边用空格填充。
 * @param  n   [整数n]
 * @param  s   [保存结果的数组]
 * @param  min [最小长度]
 */
#define abs(x) (((x) < 0)? -(x) : (x))
static void itoa(int n, char *s, int min) {
    int sign = (n < 0)? -1 : 1;
    int j = 0;
    do {
        s[j++] = abs(n % 10) + '0';
    } while ((n /= 10) != 0);
    if (sign == -1) { s[j++] = '-'; }
    while (j < min) { s[j++] = ' '; }
    s[j] = '\0';
    reverse(s);
}

static void reverse(char *s) {
    int hi = 0;
    while (s[hi] != '\0') { ++hi; }
    --hi;
    int lo = 0;
    char c;
    while (lo < hi) {
        c = s[lo];
        s[lo++] = s[hi];
        s[hi--] = c;
    }
}
