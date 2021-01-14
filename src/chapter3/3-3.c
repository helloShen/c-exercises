#include <stdio.h>

static void expand(char *s1, char *s2);
static void betterExpand(char *s1, char*s2);
static int isDigit(char c);
static int isLetter(char c);
static void test(char *s1);

int main(void) {
    char s11[] = "hello is nothing!";
    test(s11);
    char s12[] = "hello are a-z";
    test(s12);
    char s13[] = "hello is -prefix bar";
    test(s13);
    char s14[] = "hello is post- bar";
    test(s14);
}

static char s2[1024];
static void test(char *s1) {
    printf("%s\nbecome\n",s1);
    // expand(s1,s2);
    betterExpand(s1,s2);
    printf("%s\n\n",s2);
}

/*
 * 将字符串s1中的速记符号[1-5]，或者[a-z]，在s2中扩展成等价的完整列表。
 * 假设字符串s2的空间足够长。
 *
 * 这种题，不要用状态机的方法增加逻辑复杂度。
 * 直接在当前循环中读入下一个字符。
 */
static void expand(char *s1, char *s2) {
    int i, j;
    char c, d, e;
    for (i = 0; (c = s1[i]) != '\0'; i++) {
        if (((isDigit(c) && (d = s1[++i]) == '-' && (e = s1[++i]) && isDigit(e) && e >= c))
            ||
           ((isLetter(c) && (d = s1[++i]) == '-' && (e = s1[++i]) && isLetter(e) && e >= c))) {
            for (char x = c; x <= e; x++) {
                s2[j++] = x;
            }
            d = '\0'; e = '\0';
            continue;
        }
        s2[j++] = c;
        if (d != '\0') { s2[j++] = d; d = '\0'; }
        if (e != '\0') { s2[j++] = e; e = '\0'; }
    }
    s2[j++] = '\0';
}

/**
 * 像这样需要连续匹配几个字符的情况，最好就用下面这个方法，探出头，看一下后面的几个字符。
 * 这个方法比上面一个方法更好。
 */
static const char END = '\0';
static const char BAR = '-';
static void betterExpand(char *s1, char*s2) {
    int i, j;
    char c;
    for (int i = 0; (c = s1[i]) != END; i++) {
        if (isDigit(c) && s1[i+1] == BAR && isDigit(s1[i+2]) && s1[i+2] >= c) {
            for (char d = c; d <= s1[i+2]; d++) {
                s2[j++] = d;
            }
            i += 2;
        } else if (isLetter(c) && s1[i+1] == BAR && isLetter(s1[i+2]) && s1[i+2] > c) {
            for (char d = c; d <= s1[i+2]; d++) {
                s2[j++] = d;
            }
            i += 2;
        } else {
            s2[j++] = c;
        }
    }
    s2[j] = END;
}

static int isDigit(char c) {
    return (c >= 0 && c <= 9)? 1 : 0;
}
static int isLetter(char c) {
    return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'))? 1 : 0;
}
