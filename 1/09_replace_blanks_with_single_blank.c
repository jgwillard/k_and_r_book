#include <stdio.h>

/**
 * Copy program input to output, replacing each string of one or more
 * blanks with a single blank.
 *
 * Loop through input characters, printing each one to the screen. When
 * a blank is encountered, loop without doing anything until the next
 * non-blank character, then print it to the screen and return to the
 * main loop.
 */
int main() {
    int c;

    while ((c = getchar()) != EOF) {
        putchar(c);
        if (c == ' ') {
            while ((c = getchar()) == ' ') {
                // noop
            }
            putchar(c);
        }
    }
}
