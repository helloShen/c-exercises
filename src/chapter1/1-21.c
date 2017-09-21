#include "mystd.h"

static int endtab(char *line, int lim);
static const int LIM = 100;
static const char TAB = '\t';
static const char LINE_END = '\n';
static const char SPACE = ' ';
static const char STR_END = '\0';
static const int TAB_LEN = 8;

int main() {
    char line[LIM];
    int len = 0;
    while ((len = endtab(line,LIM)) != 0) {
        printf("%d:\t%s\n",len,line);
    }
}

/**
 * 思路：
 * LEV-1:       1. 每读一个字符往数组里写一个字符
 *              ----------------------------------------------------------------------------
 * LEV-2:       2. 但如果读到的是空格，先缓存起来
 *              3. 当光标到达制表符终止位，就把前面累计的空格换成一个制表符
 *              4. 如果读到的是制表符，也先当成一个空格缓存起来，然后强制把光标对齐到下一个制表符终止位
 */
static int endtab(char *line, int lim) {
    int len = 0;                    // 字符串的长度
    int cur = 0;                    // 当前光标位置
    char c;
    int spaceLen = 0;               // 统计当前末尾的空格数

    while (len < lim-1 && (c = getchar()) != EOF && c != LINE_END) {

        spaceLen = (c == SPACE || c == TAB)? ++spaceLen : 0;                // 如果是TAB，也暂时先算是一个空格，到后面再结算
        line[len++] = c; ++cur;
        if (c == TAB) { cur = (((cur - 1) / TAB_LEN) + 1) * TAB_LEN; }      // TAB算作空格之后，光标补齐到下一个制表符终止位

        if (cur % TAB_LEN == 0) {       // 每写到一个制表符终止位（光标停在终止位的下一个位置）
            if (spaceLen > 0) {         // 前面累计的空格全换成一个制表符
                len -= spaceLen;
                spaceLen = 0;
                line[len++] = TAB;
            }
        }
    }
    // 常规的数组尾处理
    if (c == LINE_END && len < lim-1) { line[len++] = LINE_END; }
    line[len] = STR_END;
    return len;
}
