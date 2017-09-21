#include "mystd.h"

static const int LEN = 32;

static unsigned setbits(unsigned x, int p, int n, unsigned y);
static char *untostr(unsigned num);

int main(void) {
    unsigned x = 234123;
    unsigned y = 21343;
    // int p = 20; int n = 5;
    int p = 10; int n = 10;
    char *sx = untostr(x);
    char *sy = untostr(y);
    printf("x = \t\t\t%-s\n",sx);
    printf("y = \t\t\t%-s\n",sy);
    free(sx); free(sy);
    x = setbits(x,p,n,y);
    char *nsx = untostr(x);
    printf("After setbits(), x = \t%-s\n",nsx);
    free(nsx);
}

static unsigned setbits(unsigned x, int p, int n, unsigned y) {
    /* 标准答案的屏蔽码是：~(~(~0 <<n) << (p+1-n))    并没有我这个好 */
    unsigned clearmask = (unsigned)(~0) >> (LEN - (p + n)) << (LEN - n) >> (p - 1);
    x = x & clearmask;
    char *maskstr = untostr(clearmask);
    printf("Mask = \t\t\t%s\n",maskstr);
    free(maskstr);
    y <<= LEN - n;
    y >>= p-1;
    return x | y;
}
static char *untostr(unsigned num) {
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
