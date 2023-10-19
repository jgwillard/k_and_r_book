#include <stdio.h>

/**
 * Count blanks, tabs, and newlines. Use `long long` for a 64-bit
 * number to avoid overflow in the case of a huge file.
 */
int main() {
    int c;
    long long nw = 0;

    while ((c = getchar()) != EOF) {
        if (c == '\n' || c == '\t' || c == ' ') {
            ++nw;
        }
    }

    printf("%lld\n", nw);
}
