/*************************************************************
 * 作为一种良好的程序风格，在switch语句最后一个分支（default分支）
 * 的后面也加上一个break语句。
 * 这样做虽然在逻辑上没必要，但当我们需要向该switch语句后添加其他分之时，
 * 这种防范措施会降低犯错误的可能性。
 ************************************************************/
#include "mystd.h"

static void escapeWhile(char *s, char* t);
static void escapeFor(char *s, char* t);

int main(void) {
    char t[] = "hello, world!";
    printf("String t = \"%s\"\n",t);
    char s[16];
    // escapeWhile(s,t);
    escapeFor(s,t);
    printf("String s = \"%s\"\n",s);
}

/**
 * 将字符串t复制到字符串s中。
 * 假设字符串s空间足够。
 * 用while的版本
 */
static void escapeWhile(char *s, char* t) {
    int curt = 0, curs = 0; char ct;
    while ((ct = t[curt++]) != '\0') {
        switch (ct) {
            case '\t': s[curs++] = '\\'; s[curs++] = 't'; break;
            case '\n': s[curs++] = '\\'; s[curs++] = 'n'; break;
            default: s[curs++] = ct; break;
        }
    }
    s[curs] = '\0';
}

/**
 * 将字符串t复制到字符串s中。
 * 假设字符串s空间足够。
 * 用for的版本
 */
static void escapeFor(char *s, char* t) {
    int ct,cs;
    char c;
    for (ct = cs = 0; (c = t[ct]) != '\0'; ct++) {
        switch (c) {
            case '\t': s[cs++] = '\\'; s[cs++] = 't'; break;
            case '\n': s[cs++] = '\\'; s[cs++] = 'n'; break;
            default: s[cs++] = c; break;
        }
    }
    s[cs] = '\0';
}
