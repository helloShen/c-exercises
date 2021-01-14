/**
 * ungets()函数，将整个字符串s压回输入中（缓冲区）
 * 不重新定义缓冲区，直接调用ungetch()
 */

// 声明getch.c中的ungetch()函数
void ungetch(char c);

void ungets(char s[]) {
    int i = 0;
    while (s[i++] != '\0');
    i -= 2;
    while (i >= 0) { ungetch(s[i--]); }
}
