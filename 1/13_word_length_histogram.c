#include <stdio.h>

#define HISTOGRAM_LENGTH 20
#define OUT 0
#define IN 1

/**
 * Print a histogram of the lengths of words in input.
 *
 * Program consists of three parts: initialization, reading input, and
 * printing the histogram.
 *
 * Initialization creates the histogram array and sets all values to 0.
 *
 * Reading input is similar to the previous exercise: we use a state
 * variable to track whether we are in a word so that we know when we
 * enter and leave a new word. When we enter a word we reset the length
 * counter to 1 and when we leave a word we record the length of the
 * word in the histogram. We also track the most frequently occurring
 * length so that we know the max height of the histogram.
 *
 * To print the histogram we start with the max height and count down,
 * and for each column we print a `#` if the value in the histogram for
 * that column is greater than or equal to the height counter.
 *
 * NOTE: a "word" in this program is any string of non-blank
 * characters, so e.g. `histogram[i]` is treated as a single word.
 */
int main() {
    // init
    int i;
    int c;
    int state;
    int is_wordbreak;
    int word_length = 0;
    int max_frequency = 0;
    int histogram[HISTOGRAM_LENGTH];
    int j;

    for (i = 0; i < HISTOGRAM_LENGTH; i++) {
        histogram[i] = 0;
    }

    // read input
    state = OUT;
    while ((c = getchar()) != EOF) {
        is_wordbreak = (c == ' ' || c == '\n' || c == '\t');
        // we have entered a word so start counting the first char
        if (!is_wordbreak && state == OUT) {
            word_length = 1;
            state = IN;
        }
        // we are in a word so continue counting
        else if (!is_wordbreak && state == IN) {
            word_length += 1;
        }
        // we are leaving a word so record length
        else if (is_wordbreak && state == IN) {
            state = OUT;
            if (word_length < HISTOGRAM_LENGTH) {
                i = word_length - 1;
            }
            else {
                i = HISTOGRAM_LENGTH - 1;
            }
            histogram[i] += 1;
            if (histogram[i] > max_frequency) {
                max_frequency = histogram[i];
            }
        }
    }

    // print histogram
    for (i = max_frequency; i > 0; i--) {
        for (j = 0; j < HISTOGRAM_LENGTH; j++) {
            if (histogram[j] >= i) {
                printf("  #");
            }
            else {
                printf("   ");
            }
        }
        putchar('\n');
    }
    for (i = 0; i < HISTOGRAM_LENGTH - 1; i++) {
        printf("%3d", i + 1);
    }
    printf("%3d+\n", HISTOGRAM_LENGTH);
}
