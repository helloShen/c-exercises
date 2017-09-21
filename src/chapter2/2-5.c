#include "mystd.h"

static int any(char *s1, char *s2);

int main(void) {
    char *s1 = "aabbccddee";
    char *s2 = "zc";
    char *s3 = "zxy";
    printf("Any \"%s\" in \"%s\"? \t%d\n",s2,s1,any(s1,s2));
    printf("Any \"%s\" in \"%s\"? \t%d\n",s3,s1,any(s1,s3));
}

static int any(char *s1, char *s2) {
    char cs1, cs2;
    for (int i = 0; (cs2 = s2[i]) != '\0'; i++) {
        int j = 0;
        while ((cs1 = s1[j]) != '\0' && cs1 != cs2) { j++; }
        if (cs1 == cs2) { return j; }
    }
    return -1;
}
