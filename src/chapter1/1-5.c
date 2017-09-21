#include "mystd.h"
#include "thermometer.h"

int main() {
    int fahr, celsius;

    celsius = UPPER;
    printf("+-----------------------+\n");
    printf("%-2s %s %2s\n","|","摄氏度-华氏度对照表","|");
    printf("+-----------------------+\n");
    printf("%8s %6s\n", "celsius", "fahr");
    while (celsius >= LOWER) {
        fahr = (9/5) * celsius + 32;
        printf("%8d %6d\n", celsius, fahr);
        celsius -= STEP;
    }
}
