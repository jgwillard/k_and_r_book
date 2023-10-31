#include <stdio.h>

#define MAXLENGTH 1000

int get_line(char line[], int maxline);

void reverse(char line[], int limit);

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

    while ((t[i] = s[i]) != '\n') {
        i++;
    }

    len = i;

    while (i >= 0) {
        s[len - i] = t[i];
        i--;
    }
    s[len + 1] = '\n';
    s[len + 2] = '\0';

}
