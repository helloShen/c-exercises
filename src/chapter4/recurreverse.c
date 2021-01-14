/**
 * 练习4-13
 * 递归reverse()函数，反转一个字符串
 */
#include <stdio.h>

static char c;

/**
 * [递归版reverse()函数，反转一个字符串]
 * @param s [需要反转的字符串]
 */
void recurreverse(char *s, int lo, int hi) {
    if (lo < hi) {
        c = s[lo];
        s[lo] = s[hi];
        s[hi] = c;
        recurreverse(s, ++lo, --hi);
    }
}
