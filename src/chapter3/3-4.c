#include <stdio.h>

static void itoa(int n, char s[]);
static void betterItoa(int n, char s[]);
static void reverse(char s[], int from, int to);

int main(void) {
    char s1[10];
    itoa(-2147483648,s1);
    printf("s1 = %s\n",s1);

    char s2[10];
    betterItoa(-2147483648,s2);
    printf("s2 = %s\n",s2);

}

/*
 * 书上的简单itoa()。
 * 不能处理Integer.MIN_VALUE，因为没办法取相反数。
 */
static void itoa(int n, char s[]) {
    int j = 0;
    if (n < 0) {
        s[j++] = '-';
        n = -n; // -(-2147483648) = -2147483648
    }
    do {
      s[j++] = n % 10 + '0';
    } while ((n /= 10) > 0);
    s[j] = '\0';
    int start = (s[0] == '-')? 1 : 0;
    reverse(s,start,j);
}

/* 反转字符串数组 */
static void reverse(char s[], int from, int to) {
    for (int i = from, j = to - 1; i < j; i++, j--) {
        char c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

/**
 * 更好的itoa()。
 * 可以处理Integer.MIN_VALUE
 */
#define abs(x) (((x) < 0)? -(x) : (x)) // 求绝对值的宏

static void betterItoa(int n, char s[]) {
    int j = 0;
    if (n < 0) { s[j++] = '-'; }
    do {
        s[j++] = abs(n % 10) + '0'; // -17 % 10 = -7
    } while ((n /= 10) != 0);
    s[j] = '\0';
    int start = (s[0] == '-')? 1 : 0;
    reverse(s,start,j);
}
