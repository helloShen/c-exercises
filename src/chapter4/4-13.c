#include <stdio.h>
#include <string.h>


void recurreverse(char *s, int lo, int hi);

/** 测试主入口 */
int main(void) {
    char s[100] = "hello,world\0";
    printf("%s\t[len=%d]\n",s,(int)strlen(s));
    recurreverse(s,0,strlen(s)-1);
    printf("%s\n",s);
}
