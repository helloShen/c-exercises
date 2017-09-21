/*
 * 答案的操作比我好：
 *      x ^ (~(~0 << n) << (p+1-n))
 * 先搞出一个掩码，从第p位开始的n位都是1，其余都是0：
 *      0001111000
 * 然后和x做XOR(^)异或操作，
 *      0001111000
 *      6666666666   ^
 *      --------------
 *      9999999999
 */
#include "mystd.h"

static unsigned invert(unsigned x, int p, int n);
static char *untostr(unsigned num);

int main(void) {
    unsigned x = 12345678;
    char *strx = untostr(x);
    printf("Origin Number = \t%s\n",strx);
    free(strx);
    unsigned invertx = invert(x,10,10);
    char *strinvertx = untostr(invertx);
    printf("Inverted Number = \t%s\n",strinvertx);
    free(strinvertx);
}

/**
 * 我的思路是：
 * 先挖出中间的信息(两边都是0)：
 *      0006666000
 * 反转以后(中间反转，两边都是1)： (1)
 *      1119999111
 * 再挖出两边的信息(中间都是1)：   (2)
 *      6661111666
 * 对(1)和(2)的结果做OR(|)或操作
 *      1119999111
 *      6661111666  |
 *      -------------
 *      6669999666
 */
static const int LEN = 32;
static unsigned invert(unsigned x, int p, int n) {
    unsigned midInfo = x >> (LEN-(p-1)-n) << (LEN-n) >> (p-1); // 0006666000
    char *strMidInfo = untostr(midInfo);
    printf("Mid Info = \t\t%s\n",strMidInfo);
    free(strMidInfo);

    unsigned invertMidInfo = ~midInfo; // 1119999111
    char *strInvertMidInfo = untostr(invertMidInfo);
    printf("Invert Mid Info = \t%s\n",strInvertMidInfo);
    free(strInvertMidInfo);

    unsigned sideMask = (unsigned)(~0) >> (LEN-(p-1)-n) << (LEN-n) >> (p-1); // 0001111000
    char *strSideMask = untostr(sideMask);
    printf("Side Mask = \t\t%s\n",strSideMask);
    free(strSideMask);

    unsigned sideInfo = x | sideMask; // 6661111666
    char *strSideInfo = untostr(sideInfo);
    printf("Side Info = \t\t%s\n",strSideInfo);
    free(strSideInfo);

    unsigned res = invertMidInfo & sideInfo; // 6669999666
    char *strRes = untostr(res);
    printf("Result = \t\t%s\n",strRes);
    free(strRes);

    return res;
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
