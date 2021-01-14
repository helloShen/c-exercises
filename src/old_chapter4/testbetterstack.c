#include <stdio.h>
#include "betterstack.h"

int main(void) {
    push(1.1);
    push(2.2);

    // printtop()
    printf("printtop: ");
    printtop();

    // copytop()
    printf("printtop: %f\n", copytop());

    // exchtop()
    exchtop();
    printf("after exchtop: ");
    printf("printtop: %f\n", copytop());

    // push()
    push(3.3);
    printf("after push()\n");
    printtop();

    // pop()
    pop();
    printf("after pop()\n");
    printtop();

    // empty()
    empty();
    printf("after empty()\n");
    printtop();
}
