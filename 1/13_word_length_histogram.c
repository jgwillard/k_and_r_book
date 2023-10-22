#include <stdio.h>

#define HISTOGRAM_LENGTH 20
#define OUT 0
#define IN 1

int main() {
    int i;
    int c;
    int state;
    int is_wordbreak;
    int word_length = 0;
    int histogram[HISTOGRAM_LENGTH];
    int j;

    for (i = 0; i < HISTOGRAM_LENGTH; i++) {
        histogram[i] = 0;
    }

    state = OUT;
    while ((c = getchar()) != EOF) {
        is_wordbreak = (c == ' ' || c == '\n' || c == '\t');
        // we have entered a word so start counting or
        if (!is_wordbreak && state == OUT) {
            word_length += 1;
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
                histogram[word_length - 1] += 1;
            }
            else {
                histogram[HISTOGRAM_LENGTH - 1] += 1;
            }
            word_length = 0;
        }
    }

    // print histogram
    for (i = 0; i < HISTOGRAM_LENGTH - 1; i++) {
        printf("Word length %d:", i + 1);
        for (j = 0; j < histogram[i]; j++) {
            putchar('#');
        }
        putchar('\n');
    }
    printf("Word length %d+:", HISTOGRAM_LENGTH);
    for (i = 0; i < histogram[HISTOGRAM_LENGTH - 1]; i++) {
        putchar('#');
    }
    putchar('\n');
}
