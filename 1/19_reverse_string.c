#include <stdio.h>

#define MAXLENGTH 1000

/**
 * Read input and copy characters into array until newline or limit is
 * reached. Return length of line.
 */
int get_line(char line[], int maxline);

/**
 * Take a line ('\n'-terminated char array) and reverse it in place,
 * keeping the newline character at the end.
 */
void reverse(char line[], int limit);

/**
 * Reverse program input one line at a time.
 */
int main() {
    int len;
    char current_line[MAXLENGTH];

    while ((len = get_line(current_line, MAXLENGTH))) {
        reverse(current_line, MAXLENGTH);
        printf("%s", current_line);
    }
}

int get_line(char s[], int lim) {
    int c;
    int i;

    for (i = 0; i < lim - 1 && (c = getchar()) != EOF && c != '\n'; i++) {
        s[i] = c;
    }

    if (c == '\n') {
        s[i] = c;
        i++;
    }

    s[i] = '\0';
    return i;
}

void reverse(char s[], int lim) {
    int i = 0;
    int len;
    char t[MAXLENGTH];

    // neither loop will not be entered for line containing only '\n'
    while ((t[i] = s[i]) != '\n') {
        i++;
    }

    len = i;

    while (i > 0) {
        // copy penultimate char (last before '\n') of t into 0th char
        // of s, then antepenultimate to 1st, and so forth
        s[len - i] = t[i - 1];
        i--;
    }

    // ensure line terminates correctly
    s[len] = '\n';
    s[len + 1] = '\0';
}
