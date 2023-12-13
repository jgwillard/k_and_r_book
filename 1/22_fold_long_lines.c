#include <stdio.h>

#define MAXLENGTH 1000
#define FOLDLENGTH 59
#define IN 1
#define OUT 0

/**
 * Read input and copy characters into array s until newline or limit
 * is reached. If a line exceeds FOLDLENGTH, break after the last non-
 * blank character before FOLDLENGTH. Return length of line.
 */
int get_folded_line(char line[], int maxline);

/**
 * Read line be line. If line length exceeds FOLDLENGTH, print on
 * multiple lines.
 */
int main() {
    char current_line[MAXLENGTH];

    while (get_folded_line(current_line, MAXLENGTH)) {
        printf("%s", current_line);
    }
}

int get_folded_line(char s[], int lim) {
    int state;
    int i;
    int c;
    int is_whitespace;
    int is_newline;
    int end_last_word_index = 0;

    state = OUT;
    for (i = 0; i < lim - 1 && (c = getchar()) != EOF; i++) {
        is_whitespace = (c == ' ' || c == '\t');
        is_newline = c == '\n';

        // copy current character to new string
        s[i] = c;

        // we are inside a word and encounter whitespace
        if (state == IN && is_whitespace) {
            end_last_word_index = i;
            state = OUT;
        }
        // we are outside a word and encounter non-whitespace, non-
        // newline characters
        else if (state == OUT && !is_whitespace && !is_newline) {
            state = IN;
        }
        // we are inside or outside a word and encounter a newline
        else if (is_newline) {
            // save null to next index and leave loop
            s[++i] = '\0';
            break;
        }
        // we reach FOLDLENGTH without having reached a newline and we
        // are outside of a word
        else if (i == FOLDLENGTH && state == OUT) {
            s[i] = '\n';
            s[++i] = '\0';
            break;
        }
        // we reach FOLDLENGTH without having reached a newline and we
        // are in a word
        else if (i == FOLDLENGTH && state == IN) {
            // go back to the last index where there was a word
            i = end_last_word_index;
            // now we have to go back and prepend the characters
            // between the previous value of i and the value of
            // end_last_word_index to the next line...
            s[i] = '\n';
            s[++i] = '\0';
            break;
        }

    }

    return i;
}
