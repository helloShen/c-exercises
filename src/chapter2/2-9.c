#include "mystd.h"

static void test(int x);
static int bitcount(int x);
static char *untostr(int num);

int main(void) {
    test(123456789);
    test(-123456789);
}
static void test(int x) {
    printf("%d = %s\n",x,untostr(x));
    printf("It has %d 1 bits!\n\n",bitcount(x));
}

static int bitcount(int x) {
    int count = 0;
    while (x != 0) {
        ++count;
        x &= (x-1);
    }
    return count;
}

static char *untostr(int num) {
    char *bits = malloc(33 * sizeof(char));
    bits[32] = '\0';
    unsigned mask = 1;
    for (int i = 31; i >= 0; i--,mask <<= 1) {
        if ((num & mask) == 0) {
            bits[i] = '0';
        } else {
            bits[i] = '1';
        }
    }
    return bits;
}
