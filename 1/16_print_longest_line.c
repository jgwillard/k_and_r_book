#include <stdio.h>

#define MAXLINE 100

int _getline(char line[], int maxline);
void copy(char to[], char from[]);

int main() {
    int len;
    int max;
    char line[MAXLINE];
    char longest[MAXLINE];
    int c;
    int ends_with_newline;
    int print_newline = 0;

    max = 0;
    while ((len = _getline(line, MAXLINE)) > 0) {
        ends_with_newline = line[len - 1] != '\n';
        if (ends_with_newline) {
            // line was over limit; count chars until newline
            while ((c = getchar()) != EOF && c != '\n') {
                len++;
            }
        }

        if (len > max) {
            print_newline = ends_with_newline;
            max = len;
            copy(longest, line);
        }

    }

    if (max > 0) {
        printf("%s", longest);
    }

    if (print_newline) {
        putchar('\n');
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

void copy(char to[], char from[]) {
    int i;

    i = 0;
    while ((to[i] = from[i]) != '\0') {
        i++;
    }
}
