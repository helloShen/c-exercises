#include "mystd.h"
#include "limits.h"

int main(void) {
    /*
     * int:
     * [-2147483648,2147483647]
     * 4 bytes, 32 bits
     */
    printf("Maximum Integer = %d = 0x%x\n",INT_MAX, INT_MAX);
    printf("Minimum Integer = %d = 0x%x\n\n",INT_MIN, INT_MIN);
    /*
     * unsigned int:
     * [0,4294967295]
     * 4 bytes, 32 bits
     */
    printf("Maximum Unsigned Integer = %u = 0x%x\n",UINT_MAX, UINT_MAX);
    printf("Minimum Unsigned Integer = %u = 0x%x\n\n",0, 0);
    /*
     * char:
     * [-128,127]
     * 1 byte, 8 bits
     */
    printf("Maximum Char = %d = 0x%x\n",CHAR_MAX, CHAR_MAX);
    printf("Minimum Char = %d = 0x%x\n",CHAR_MIN, CHAR_MIN);
    /* 位操作构造，下面的int,long等都可以用这个方法构造 */
    // 注意：这里必须用(unsigned char)转型，否则>>右位移出来的就是1。这里我们想要的首位清零。
    // >>右位移操作的规则如下：
    //      1. signed: 前面加1
    //      2. unsigned: 前面加0
    // 所以这里的unsigned >> 相当于Java里的 >>>
    char charMax = (char)((unsigned char)~0 >> 1);
    char charMin = (char)~charMax;
    printf("x = 0x%x\n", x);
    printf("y = 0x%x\n", y);
    printf("Maximum Char = %d = 0x%x\n", charMax, charMax);
    printf("Minimum Char = %d = 0x%x\n\n", charMin, charMin);
    /*
     * unsigned char:
     * [0,255]
     * 1 byte, 8 bits
     */
    printf("Maximum Unsigned Char = %d = 0x%x\n",UCHAR_MAX, UCHAR_MAX);
    printf("Minimum Unsigned Char = %d = 0x%x\n\n",0, 0);
    /*
     * unsigned char:
     * [0,255]
     * 1 byte, 8 bits
     */
    printf("Maximum Unsigned Char = %d = 0x%x\n",UCHAR_MAX, UCHAR_MAX);
    printf("Minimum Unsigned Char = %d = 0x%x\n\n",0, 0);
    /*
     * short:
     * [-32768,32767]
     * 2 bytes, 16 bits
     */
    printf("Maximum Short = %d = 0x%x\n",SHRT_MAX, SHRT_MAX);
    printf("Minimum Short = %d = 0x%x\n\n",SHRT_MIN, SHRT_MIN);
    /*
     * unsigned short:
     * [0,65535]
     * 2 bytes, 16 bits
     */
    printf("Maximum Unsigned Short = %d = 0x%x\n",USHRT_MAX, SHRT_MAX);
    printf("Minimum Unsigned Short = %d = 0x%x\n\n",0, 0);
    /*
     * long:
     * [-9223372036854775808,9223372036854775807]
     * 8 bytes, 64 bits
     */
    printf("Maximum Long = %ld = 0x%lx\n",LONG_MAX, LONG_MAX);
    printf("Minimum Long = %ld = 0x%lx\n\n",LONG_MIN, LONG_MIN);
    /*
     * unsigned long:
     * [0,18446744073709551615]
     * 8 bytes, 64 bits
     */
    printf("Maximum Unsigned Long = %lu = 0x%lx\n",ULONG_MAX, ULONG_MAX);
    printf("Minimum Unsigned Long = %lu = 0x%lx\n\n",0l,0l);
}
