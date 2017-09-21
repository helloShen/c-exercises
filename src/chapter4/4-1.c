/********************************************************
 * 第一种方法从左往右匹配，匹配到了以后不返回继续匹配。
 * 第二种方法从右往左匹配，匹配到了直接返回。
 *
 * 第二种方法比第一种方法效率更高。
 *******************************************************/
#include "mystd.h"
#include <string.h>

static int strrindex(char *s, char *t);
static int strrindex2(char *s, char *t);

int main(void) {
    char s1[] = "could you and I with Fate conspire. Would not we shatter it to bits.";
    char t1[] = "ould";
    // printf("Last index of \"ould\" is: %d\n",strrindex(s1,t1));
    printf("Last index of \"ould\" is: %d\n",strrindex2(s1,t1));
}

/** 返回字符串t在字符串s最右边出现的位置，没有匹配到返回-1. */
/** 从左往右匹配，如果匹配到，不返回继续匹配 */
static int strrindex(char *s, char *t) {
    int index = -1;
    char cs, ct;
    for (int i = 0; (cs = s[i]) != '\0'; i++) {
        int k = 0;
        for (int j = i; (ct = t[k]) != '\0' && ct == s[j]; j++,k++) { }
        if (k > 0 && ct == '\0') { index = i; }
    }
    return index;
}

/** 返回字符串t在字符串s最右边出现的位置，没有匹配到返回-1. */
/** 第二种方法从右往左匹配，匹配到了直接返回。*/
static int strrindex2(char *s, char *t) {
    int i,j,k;
    for (i = strlen(s) - strlen(t); i >= 0; i--) {
        for (j = i, k = 0; s[j] == t[k] && t[k] != '\0'; j++,k++) { }
        if (k > 0 && t[k] == '\0') { return i; }
    return -1;
}
