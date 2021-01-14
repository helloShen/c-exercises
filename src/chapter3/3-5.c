/************************************************
 * 我的版本比答案好一点。
 * 答案还是不能处理Integer.MIN_VALUE.
 * 我的版本可以。
 ***********************************************/
#include <stdio.h>

static void itob(int n, char *s, int b);
static void reverse(char *s, int from, int to);

int main(void) {
    char s[10];
    int x = -2147483648;
    itob(x,s,16);
    printf("%d -> %s\n",x,s);

    int y = 1234567;
    itob(y,s,16);
    printf("%d -> %s\n",y,s);

}

/**
 * 将n转换成以b为底的数，并将转换结果以字符的形式保存到字符串s中
 * b <= 35，因为只有26个字母
 * 假设s足够长
 */
#define abs(x) (((x) < 0)? (-x) : (x));
static void itob(int n, char *s, int b) {
    int sign = (n < 0)? -1 : 1;
    int i = 0;
    do {
        // printf("n = %d\n",n);
        int remain = abs(n % b);
        s[i++] = (remain > 9)? remain - 10 + 'a' : remain + '0';
    } while ((n /= b) != 0);
    if (sign == -1) { s[i++] = '-'; }
    reverse(s,0,i-1);
    s[i] = '\0';
}

/* 反转字符串s[from,to]范围内的字符。前后都是闭区间。 */
static void reverse(char *s, int from, int to) {
    char c;
    while (from < to) {
        c = s[from];
        s[from++] = s[to];
        s[to--] = c;
    }
}
