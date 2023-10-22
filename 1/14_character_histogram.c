#include <stdio.h>

#define ALPHA_LEN 26
#define DEC_LEN 10

/**
 * Print a histogram of the frequencies of different characters in
 * program input.
 *
 * NOTE: This program counts decimal digits and upper- and lower-
 * case alphabetical characters only.
 */
int main() {
    int i;
    int c;
    int n_digit[DEC_LEN];
    int n_alpha_upper[ALPHA_LEN];
    int n_alpha_lower[ALPHA_LEN];
    int j;

    for (i = 0; i < ALPHA_LEN; i++) {
        if (i < DEC_LEN) {
            n_digit[i] = 0;
        }
        n_alpha_upper[i] = 0;
        n_alpha_lower[i] = 0;
    }

    while ((c = getchar()) != EOF) {
        if (c >= '0' && c <= '9') {
            n_digit[c - '0']++;
        }
        else if(c >= 'A' && c <= 'Z') {
            n_alpha_upper[c - 'A']++;
        }
        else if(c >= 'a' && c <= 'z') {
            n_alpha_lower[c - 'a']++;
        }
    }

    // horizontal histogram because there are so many columns
    for (i = 0; i < DEC_LEN; i++) {
        printf("%c: ", '0' + i);
        for (j = 0; j < n_digit[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }

    for (i = 0; i < ALPHA_LEN; i++) {
        printf("%c: ", 'A' + i);
        for (j = 0; j < n_alpha_upper[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }

    for (i = 0; i < ALPHA_LEN; i++) {
        printf("%c: ", 'a' + i);
        for (j = 0; j < n_alpha_lower[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
}
