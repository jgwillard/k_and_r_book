#include <stdio.h>

#define IN 1
#define OUT 0

/**
 * Print program input one word per line.
 *
 * There are four cases that need to be handled:
 *
 * 1. If we are inside a word and encounter a non-whitespace character
 *    we just print it.
 * 2. If we are inside a word and encounter whitespace, we have left
 *    the word, so print newline and record that we are outside a word.
 * 3. If we are outside a word and we encounter a non-whitespace
 *    character, we have reentered a word, so print the character and
 *    record that we are inside a word.
 * 4. If we are outside a word already and encounter more whitespace,
 *    do nothing.
 */
int main() {
    int state;
    int c;
    int is_whitespace;

    state = OUT;
    while ((c = getchar()) != EOF) {
        is_whitespace = (c == ' ' || c == '\n' || c == '\t');
        // we are inside a word and encounter non-whitespace
        if (state == IN && !is_whitespace) {
            putchar(c);
        }
        // we are inside a word and encounter whitespace
        else if (state == IN && is_whitespace) {
            state = OUT;
            putchar('\n');
        }
        // we are outside a word and encounter non-whitespace
        else if (state == OUT && !is_whitespace) {
            state = IN;
            putchar(c);
        }
        // we are outside a word and encounter whitespace
        else if (state == OUT && is_whitespace) {
            // NOTE this branch is not necessary but is included for
            // completeness -- noop
        }
    }
}
