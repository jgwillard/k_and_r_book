#include <stdio.h>

#define MAXLENGTH 1000
#define IN 1
#define OUT 0

/**
 * Read input and copy characters into array s until newline or limit
 * is reached. If a line contains trailing blanks or tabs between its
 * last word and the newline, do not copy trailing whitespace into
 * array. Return length of line.
 */
int get_trimmed_line(char line[], int maxline);

/**
 * Remove trailing blanks and tabs from each line of input, and delete
 * entirely blank lines.
 *
 * Use get_trimmed_line to read input line by line, such that all
 * trailing whitespace is removed. If a line has a length of 1, (i.e.
 * it consists only of a newline), do nothing; otherwise print line.
 */
int main() {
    int len;
    char current_line[MAXLENGTH];

    while ((len = get_trimmed_line(current_line, MAXLENGTH))) {
        if (len > 1) {
            printf("%s", current_line);
        }
    }
}

int get_trimmed_line(char s[], int lim) {
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
        // we are inside a word and encounter a newline
        else if (state == IN && is_newline) {
            // save null to next index and leave loop
            s[++i] = '\0';
            break;
        }
        // we are outside a word and encounter a newline (including
        // the case where the line contains only a single newline)
        else if (state == OUT && is_newline) {
            // go back to the last index where there was a word
            i = end_last_word_index;
            s[i] = '\n';
            s[++i] = '\0';
            break;
        }

    }

    return i;
}
