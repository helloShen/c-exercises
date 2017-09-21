#include "mystd.h"

static double myatof(char *s);
static int myatoi(char *s, int *i);

int main(void) {
    char s[] = "123.45e6";
    printf("Number = %f\n",myatof(s));
}

static double myatof(char *s) {
    int cur = 0;
    while (s[cur] == ' ') { ++cur; }            // skip leading spaces
    int sign = (s[cur] == '-')? -1 : 1;           // treat sign
    if (s[cur] == '+' || s[cur] == '-') { ++cur; }
    // loop
    double res = 0.0;
    double p = 1.0;
    char c;
    int beginP1;
    while ((c = s[cur++]) != '\0') {
        if (c >= '0' && c <= '9') {
            res = 10 * res + c - '0';
            if (beginP1) { p /= 10.0; }
        } else if (c == '.') {
            beginP1 = 1;
        } else if (c == 'e' || c == 'E') {
            int p2 = myatoi(s,&cur);
            for (int i = p2; i != 0; (i < 0)? i++ : i--) {
                p = (i < 0)? p / 10.0 : p * 10.0; // 连续除以10，不要乘以0.1。因为0.1比实际0.1要小一点，不精确。
            }
        }
    }
    // printf("Sign = %f\n",(double)sign);
    // printf("Result = %f\n",res);
    // printf("Power = %f\n",p);
    return (double)sign * res * p;
}

static int myatoi(char *s, int *i) {
    int res = 0;
    int sign = (s[*i] == '-')? -1 : 1;
    if (s[*i] == '+' || s[*i] == '-') { (*i)++; }
    char c;
    while ((c = s[(*i)++]) != '\0' && (c >= '0' && c <= '9')) {
        // printf("Char c = %c\n",c);
        // printf("Res = %d\n",res);
        res = res * 10 + (c - '0');
    }
    return sign * res;
}
