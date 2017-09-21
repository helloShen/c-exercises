#include "mystd.h"
#include "thermometer.h"

void ctof();

int main() {
    ctof();
}

void ctof() {
    int fahr, celsius;

    celsius = LOWER;
    printf("+-----------------------+\n");
    printf("%-2s %s %2s\n","|","摄氏度-华氏度对照表","|");
    printf("+-----------------------+\n");
    printf("%8s %6s\n", "celsius", "fahr");
    while (celsius <= UPPER) {
        fahr = (9/5) * celsius + 32;
        printf("%8d %6d\n", celsius, fahr);
        celsius += STEP;
    }
}
