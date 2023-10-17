#include <stdio.h>

int main() {
    float celsius;
    float fahr;
    int lower = 0;
    int upper = 300;
    int step = 20;

    celsius = lower;
    printf("Celsius  Fahrenheit\n");
    while (celsius <= upper) {
        fahr = (celsius * (9.0 / 5.0)) + 32.0;
        printf("%3.0f %15.0f\n", celsius, fahr);
        celsius += step;
    }
}
