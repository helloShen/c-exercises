#include "mystd.h"

static unsigned rightrot(unsigned x, int n);
static char *untostr(unsigned num);

int main(void) {
    unsigned x = 12345678;
    rightrot(x,10);
}
/* 返回x向右旋转n位以后的数字。右边溢出的位会从左边重新插入。实际就是交换左右两部分。 假设n是合法的。*/
/* 书上的标准答案还是用掩码的方法做。这题可以有很多种解法 */
static unsigned rightrot(unsigned x, int n) {
    printf("Original x = \t%s\n",untostr(x));
    unsigned leftN = x << (32 - n);
    printf("Left n bits = \t%s\n",untostr(leftN));
    unsigned rightRest = x >> n;
    printf("Right Rest = \t%s\n",untostr(rightRest));
    unsigned res = leftN | rightRest;
    printf("Result = \t%s\n",untostr(res));
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
