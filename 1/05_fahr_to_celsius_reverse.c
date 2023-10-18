#include <stdio.h>

#define LOWER 0
#define UPPER 300
#define STEP 20

int main() {
    float fahr;
    float celsius;

    printf("Fahrenheit  Celsius\n");
    for (fahr = UPPER; fahr >= LOWER; fahr -= STEP) {
        celsius = 5.0 / 9.0 * (fahr - 32.0);
        printf("%3.0f %15.1f\n", fahr, celsius);
    }
}
