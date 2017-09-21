#include "mystd.h"
#include "thermometer.h"

int main() {
    float fahr, celsius;

    fahr = LOWER;
    printf("+-----------------------+\n");
    printf("%-2s %s %2s\n","|","华氏度-摄氏度对照表","|");
    printf("+-----------------------+\n");
    printf("%6s %8s\n", "fahr", "celsius");
    while (fahr <= UPPER) {
        celsius = (5.0/9.0) * (fahr-32.0);
        printf("%6.0f %8.1f\n", fahr, celsius);
        fahr += STEP;
    }
}
