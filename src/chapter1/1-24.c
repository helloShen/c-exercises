/********************************************************
 * 用数组模拟Stack
 * 这题答案书是错的。因为光是计数，像[(])这种情况会被认为是正确的
 * 所以必须用Stack
 *
 * 基本思路还是把“注释态”和“字符态”的行为独立出去，
 * 这两种状态不检查括号关闭情况
 *
 * check()函数既调度状态，又检查括号。
 *
 * 检查括号的策略是，遇到一个左括号，就把对应的右括号写入栈。
 * 遇到右括号，就弹出栈中的首元素，检查括号类型是否匹配。
 * 最后读完文件，再检查栈中有没有遗留未正确关闭的括号。
 *
 * 还有一个line变量统计当前行数，便于在发现错误时通知用户。
 *******************************************************/
#include "mystd.h"

static int eof(void);
static int check(char c);
static int inSoftComment(void);
static int inHardComment(void);
static int inQuote(char begin);
static void plusLine(void);


// 符号常量不变
static const char QUOTE = '\"';
static const char APOSTROPHE = '\'';
static const char SLASH = '/';
static const char ANTI_SLASH = '\\';
static const char ASTERISK = '*';
static const char ENTER = '\n';
static const char LEFT_BRACE = '{';
static const char RIGHT_BRACE = '}';
static const char LEFT_BRACKET = '[';
static const char RIGHT_BRACKET = ']';
static const char LEFT_PARENTHESE = '(';
static const char RIGHT_PARENTHESE = ')';

// 结果常量
static const int T = 0;
static const int NOT_MATCH = 1;
static const int NOT_CLOSE = 2;
static const int SOF = 3;

// 用数组模仿Stack
static const int MAX = 1000;
static int stack[MAX];
static int cursor = 0;
static int line = 1;



/* 主入口 */
int main(void) {
    int res = check(getchar());
    if (res == T) {
        printf("The file is OK!\n");
    } else if (res == NOT_CLOSE){
        printf("File wrong! Util to the end of file, %c not close!\n",stack[cursor-1]);
    } else if (res == NOT_MATCH){
        printf("File wrong! Check line %d, should be %c\n",line,stack[cursor]);
    } else if (res == SOF) {
        printf("At line %d My Stack Over Flow!\n",line);
    } else {
        printf("ERROR!\n");
    }
}

/* 文件尾，检查是否所有括号都配对了 */
static int eof(void) {
    if (cursor == 0) {
        return T;
    } else {
        return NOT_CLOSE;
    }
}
/* 状态机主调度 */
static int check(char c) {
    if (c == EOF) { return eof(); } // base case
    if (c == QUOTE || c == APOSTROPHE) {
        return inQuote(c);
    } else if (c == SLASH) {
        char d = getchar();
        if (d == ASTERISK) {
            return inHardComment();
        } else if (d == SLASH) {
            return inSoftComment();
        } else {
            return check(d);
        }
    } else if (c == LEFT_BRACE || c == LEFT_BRACKET || c == LEFT_PARENTHESE) {
        if (cursor == MAX) { return SOF; } // 内存溢出
        if (c == LEFT_BRACE) { stack[cursor++] = RIGHT_BRACE; }
        if (c == LEFT_BRACKET) { stack[cursor++] = RIGHT_BRACKET; }
        if (c == LEFT_PARENTHESE) { stack[cursor++] = RIGHT_PARENTHESE; }
    } else if (c == RIGHT_BRACE || c == RIGHT_BRACKET || c == RIGHT_PARENTHESE) {
        if (cursor == 0) { return NOT_MATCH; } // 括号不匹配，报告行数
        if (stack[--cursor] != c) { return NOT_MATCH; } // 括号不匹配，报告行数
    } else if (c == ENTER) {
        plusLine();
    }
    return check(getchar());
}

/* 跳过检查，直到单行注释尾 */
static int inSoftComment(void) {
    char c;
    while ((c = getchar()) != EOF) {
        if (c == ENTER) { ++line; return check(getchar()); } // 回车终止单行注释
    }
    return eof();
}

/* 跳过检查，直到多行注释尾 */
static int inHardComment(void) {
    char c, d;
    c = getchar();
    while (c != EOF && (d = getchar()) != EOF) {
        if (c == ASTERISK && d == SLASH) {
            return check(getchar()); // 星号加一个斜杠，结束多行注释
        } else if (c == ENTER){
            plusLine();
        } else {
            c = d;
        }
    }
    if (c == ENTER) { plusLine(); }
    return eof();
}

/* 跳过检查，直到字符串尾 */
static int inQuote(char begin) {
    char c, d;
    while ((c = getchar()) != EOF) {
        if (c == ANTI_SLASH) {
            d = getchar();
            if (d == EOF) { return eof(); } // 豁免下一个转义字符
        } else if (c == begin) { // 单引号或者双引号结束字符串
            return check(getchar());
        } else if (c == ENTER) {
            plusLine();
        }
    }
    return eof();
}

/* 行数加1 */
static void plusLine(void) {
    // printf("Line#%d: just closed %c\n",line,stack[cursor]);
    ++line;
}
