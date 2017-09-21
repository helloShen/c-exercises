#include "mystd.h"

static const int LIM = 200;
static int mygetline(char s[], int lim);

/* 这题答案的做法不够好，会有bug: 当数组长度不够写入整行，但如果写入到一半，末尾（实际行的中间）正好有空格或制表符，也会错误地进行删除 */
/* 所以正确的做法应该像我这样，只统计行尾的空格和制表符， 然后根据长度回退换行符和\0字符串结尾符的位置 */
int main() {
    char line[LIM];
    int len = 0, index = 0;
    while ((len = mygetline(line,LIM)) != 0) {
        if (len > 1) { printf("%d:\t%s\t[lenght = %d]\n",++index,line,len); }
    }
}

/* 返回下一行的长度，将其写入数组s */
static int mygetline(char s[], int lim) {
    char c;
    int cur = 0; // 指向当前写入的字符下标
    int tailsize = 0; // 记录行尾制表符和空格的长度
    while ((c = getchar()) != EOF && c != '\n') {
        if (c == '\t' || c == ' ') {
            tailsize++;
        } else { // 表明之前累计的空格和制表符不在行尾，计数器归零
            tailsize = 0;
        }
        if (cur < lim-1) { s[cur] = c; }
        cur++;
    }
    while (tailsize-- > 0) { --cur; } // 去掉行尾的空格和制表符
    if (c == '\n' && cur < lim-1) { s[cur++] = '\n'; }
    if (cur < lim-1) {
        s[cur] = '\0';
    } else {
        s[lim-1] = '\0';
    }
    return cur;
}
