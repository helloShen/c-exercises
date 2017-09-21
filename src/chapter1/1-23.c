/**************************************************************************
 * 有限状态机的方法处理注释
 * 看上去好像有8种状态，其实只分为3个大方向。
 *      1. 普通状态
 *      2. 注释状态
 *      3. 字符串状态
 *
 * 其中“注释”有两种：
 *      1. // 单行注释
 *      2. /* 多行注释
 *
 * “字符串状态”也分两种：
 *      1. "..."双引号字符串
 *      2. '.'单引号单个字符
 *
 * "注释状态"需要连续读到两个字符，才能判定，所以需要一个“半开始状态”和“半关闭状态”
 *
 * “字符串状态”中还要处理'\'反斜杠的转意字符问题，所以在加一个“转意字符状态”
 *
 *************************************************************************/

#include "mystd.h"

// 普通态
static const int NORMAL = 0;            // 普通态
// 注释态
static const int HARD_COMMENT = 7;      // 多行注释态
static const int SOFT_COMMENT = 8;      // 单行注释态
static const int TO_START = 1;          // 预备进入注释态
static const int TO_CLOSE = 2;          // 预备结束注释态
// 字符态
static const int STRING = 3;            // 字符串态
static const int CHAR = 5;              // 单字符态
static const int STR_TRANS = 4;         // 字符串中的转意字符
static const int CHAR_TRANS = 6;        // 单个字符转意


// 符号常量
static const char QUOTE = '\"';
static const char APOSTROPHE = '\'';    // 看到这个注释就错了。需要正确处理转义符，才能去掉这个注释
static const char SLASH = '/';
static const char ANTI_SLASH = '\\';
static const char ASTERISK = '*';
static const char ENTER = '\n';

int main(void) {
    char c;
    int state = NORMAL;
    while ((c = getchar()) != EOF) {
        switch (state) {
            case NORMAL:                                        // 还没进入4大主状态
                if (c == SLASH) {
                    state = TO_START;
                } else if (c == QUOTE) {
                    state = STRING; putchar(c);
                } else if (c == APOSTROPHE) {
                    state = CHAR; putchar(c);
                } else {
                    putchar(c);
                }
                break;
            case TO_START:                                      // 预备进入两种注释状态
                if (c == SLASH) {
                    state = SOFT_COMMENT;
                } else if (c == ASTERISK) {
                    state = HARD_COMMENT;
                } else {
                    putchar(SLASH); putchar(c); state = NORMAL;
                }
                break;
            case STRING:                                        // 字符串状态
                putchar(c);
                if (c == QUOTE) {
                    state = NORMAL;
                } else if (c == ANTI_SLASH) {
                    state = STR_TRANS;
                }
                break;
            case STR_TRANS:                                     // 字符串状态的附属转义字符状态
                putchar(c); state = STRING; break;
            case CHAR:                                          // 字符状态
                putchar(c);
                if (c == APOSTROPHE) {
                    state = NORMAL;
                } else if (c == ANTI_SLASH) {
                    state = CHAR_TRANS;
                }
                break;
            case CHAR_TRANS:                                    // 字符状态的附属转义字符状态
                putchar(c); state = CHAR; break;
            case HARD_COMMENT:                                  // 换行不打断的多行注释状态
                if (c == ASTERISK) { state = TO_CLOSE; }
                break;
            case SOFT_COMMENT:                                  // 换行就结束的单行注释状态
                if (c == ENTER) { putchar(c); state = NORMAL; }
                break;
            case TO_CLOSE:                                      // 预备关闭两种注释状态
                if (c == SLASH) { state = NORMAL; }
            default: break;
        }
    }
}
