#include <stdio.h>

#define MAXLINE 1000
#define MINLINE 80

/**
 * Read input and copy characters into array until newline or limit is
 * reached. Return length of line.
 */
int _getline(char line[], int maxline);

/**
 * Read input line by line and print all lines longer than MINLINE. If
 * the line length exceeds MAXLINE, print as much of the line as
 * possible up to MAXLINE characters.
 */
int main() {
    int len;
    char line[MAXLINE];
    int c;
    int ends_with_newline;

    while ((len = _getline(line, MAXLINE)) > 0) {
        ends_with_newline = line[len - 1] != '\n';
        if (ends_with_newline) {
            // line was over limit; count chars until newline
            while ((c = getchar()) != EOF && c != '\n') {
                len++;
            }
        }

        if (len > MINLINE) {
            printf("%s", line);

            if (ends_with_newline) {
                putchar('\n');
            }
        }

    }
}

int _getline(char s[], int lim) {
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
