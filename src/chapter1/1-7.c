#include "mystd.h"

int main() {
    int i = EOF;
    printf("EOF on my system is: %d\n",i);
    printf("EOF on my system is: %c\n",i);

    union eof_val {
        int ival;
        char cval;
        float fval;
        double dval;
        unsigned char uc[sizeof(double)];
    } eof;

    eof.ival = EOF;

    printf("EOF to int = %d\n", eof.ival);        /* output: -1 */
    printf("EOF to char = %d\n", (unsigned char)eof.cval);       /* output: � */
    printf("EOF to float = %f\n", eof.fval);      /* output: nan */
    printf("EOF to double = %f\n", eof.dval);     /* output: 0.000000 */
    printf("EOF to char = %d\n", (unsigned char)eof.uc[0]);     /* output: 0.000000 */
}
