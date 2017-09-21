#include "mystd.h"

static int lower(int c);

int main(void) {
    for (int i = 'a'; i <= 'z'; i++) {
        printf("%c -> %c\n",i,lower(i));
    }
    for (int i = 'A'; i <= 'Z'; i++) {
        printf("%c -> %c\n",i,lower(i));
    }
}

static int lower(int c) {
    return (c >= 'A' && c <= 'Z')? c - 'A' + 'a' : c;
}
