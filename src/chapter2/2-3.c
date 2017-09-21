#include "mystd.h"
#include <limits.h>
#include <string.h>

static int check(char *str);
static int htoi(char *str);

int main(void) {
    char *str1 = "0x7fffffff";
    char *str2 = "0x80000000";
    printf("%s -> %d\n",str1,htoi(str1));
    printf("%s -> %d\n",str2,htoi(str2));
}

static int htoi(char *str) {
    int start = check(str);
    if (start == -1) { printf("LENGTH ERROR!\n"); return 0; }
    int strLen = strlen(str);
    char c;
    int res = 0;
    for (int i = start; i < strLen; i++) {
        c = str[i];
        int num = 0;
        if (c >= '0' && c <= '9') {
            num = c - '0';
        } else if (c >= 'a' && c <= 'f') {
            num = 10 + c - 'a';
        } else if (c >= 'A' && c <= 'F') {
            num = 10 + c - 'A';
        } else {
            printf("FORMAT ERROR!\n"); return 0;
        }
        res = (res << 4) + num;
    }
    return res;
}

/*
 * check the length of input string
 * return the start index if the format is correct
 * otherwise return -1.
 * 注意！可以检查输入字符串的长度，也可以不检查。
 * 太长的字符串转换的结果，无非是超过INT_MAX，然后变成负数。
 * atoi函数的源码就是这么处理的。
 *
 * 当然我这里检查长度和格式也没有什么错。
 */
static int check(char *str) {
    int strLen = strlen(str);
    int start = 0;
    if (strLen > 1 && str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) { start = 2; }
    int hexLen = strLen - start;
    if (hexLen == 0 || hexLen > 8) {
        return -1;
    } else {
        return start;
    }
}
