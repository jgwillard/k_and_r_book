#include <stdio.h>

int main() {
    float fahr;
    float celsius;
    int lower = 0;
    int upper = 300;
    int step = 20;

    fahr = lower;
    printf("Fahrenheit  Celsius\n");
    while (fahr <= upper) {
        celsius = 5.0 / 9.0 * (fahr - 32.0);
        printf("%3.0f %15.1f\n", fahr, celsius);
        fahr += step;
    }
}
