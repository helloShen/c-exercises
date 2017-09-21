#include "mystd.h"

static void sqeezeAll(char *s1, char *s2);
static void sqeeze(char *s, char c);

int main (void) {
    char s1[] = "aabbccddee";
    char s2[] = "ac";
    printf("S1 = %s\n",s1);
    printf("S2 = %s\n",s2);
    sqeezeAll(s1,s2);
    printf("S1 retains S2 = %s\n",s1);
}


static void sqeezeAll(char *s1, char *s2) {
    int i = 0;
    char c;
    while ((c = s2[i++]) != '\0') {
        sqeeze(s1,c);
    }
}
static void sqeeze(char *s, char in) {
    int fast = 0,slow = 0;
    char c;
    while ((c = s[fast++]) != '\0') {
        if (c != in) { s[slow++] = c; }
    }
    s[slow] = '\0';
}
