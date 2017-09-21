/*****************************************************************************
 *
 * 书上的标准答案，大方向也是分成三种主要状态。
 *      1. 普通状态
 *      2. 注释状态
 *      3. 字符状态
 *
 * 区别是它把状态机模块化了。主要分成三个模块，
 *      模块1：普通状态下正常输出字符。在特定条件下进入注释状态，或字符状态。
 *      模块2：注释状态下输出字符（也就是不输出）
 *      模块3：字符状态下输出字符。（屏蔽注释，以及处理转义符）
 *
 * 从代码可以看出来，写这代码的程序员的思路和我是一样的。
 * 也注意到了各种情况混在一起具体处理的细节很复杂，
 * 所以策略就是一开始就用一个调度函数，把三大主要状态的操作切分在不同的子函数里。
 * 所以逻辑条理看起来比状态机要清楚。
 *
 ****************************************************************************/
#include "mystd.h"

// 符号常量不变
static const char QUOTE = '\"';
static const char APOSTROPHE = '\'';
static const char SLASH = '/';
static const char ANTI_SLASH = '\\';
static const char ASTERISK = '*';
static const char ENTER = '\n';

static void readAndWrite(char c);
static void inHardComment();
static void inSoftComment();
static void inQuote(char begin);

int main(void) {
    readAndWrite(getchar());
}

/* 正常状态。遇到注释则进入注释态，遇到单双引号进入字符态。 */
static void readAndWrite(char c) {
    if (c == EOF) { return; } // base case可以在一开始单独拎出来
    if (c == QUOTE || c == APOSTROPHE) {
        inQuote(c);
    } else if (c == SLASH) {
        char next = getchar();
        if (next == ASTERISK) {
            inHardComment();
        } else if (next == SLASH) {
            inSoftComment();
        } else {
            putchar(c);
            if (next != EOF){ putchar(next); }
        }
    } else {
        putchar(c);
    }
    readAndWrite(getchar());
}

/* 专门打印注释。注释结束则回调readAndWrite()。单行注释，或者多行注释。屏蔽单引号和双引号。 */
static void inSoftComment(void) {
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ENTER) { return readAndWrite(c); } // 回到正常状态
    }
}
static void inHardComment(void) {
    char c, next;
    while ((c = getchar()) != EOF) {
        if (c == ASTERISK) {
            next = getchar();
            if (next == SLASH) { return readAndWrite(getchar()); }
        }
    }
}

/* 专门打印字符。单引号“单字符”状态，或者双引号“字符串”状态。屏蔽注释，还需处理转义符。 */
static void inQuote(char begin) {
    char c, next;
    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ANTI_SLASH) {
            next = getchar();
            if (next != EOF) {
                putchar(next);
            } else {
                return;
            }
        } else if (c == begin) { // 结束字符态，回到普通态
            return readAndWrite(getchar());
        }
    }
}
