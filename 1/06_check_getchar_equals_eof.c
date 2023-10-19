#include <stdio.h>

/**
 * Verify that that the expression `getchar() != EOF` is either 0 or 1.
 *
 * Accepts input and print the value of the above expression. When
 * expression is 0, exit loop. Will have the effect of printing 1 for
 * every character of input until EOF, when it will print 0 and stop.
 */
int main() {
    int c;

    while (1) {
        c = getchar() != EOF;
        printf("%d\n", c);
        if (!c) {
            break;
        }
    }
}
