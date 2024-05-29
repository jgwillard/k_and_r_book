#include <stdio.h>

#define MAXLINE 100

/**
 * Copies string `from` to `to`, converting characters like newline and
 * tab to visible escape sequences.
 */
void escape(char to[], char from[])
{
    int i, j;

    i = j = 0;
    for (i = 0; from[i] != '\0'; i++)
    {
        switch (from[i])
        {
        case '\t':
            to[j++] = '\\';
            to[j++] = 't';
            break;
        case '\n':
            to[j++] = '\\';
            to[j++] = 'n';
            break;
        default:
            to[j++] = from[i];
            break;
        }
    }
    to[j] = '\0';
}

/**
 * Copies string `from` to `to`, converting escape sequences `\n` and
 * `\t` into the real characters newline and tab.
 */
void unescape(char to[], char from[])
{
    int i, j;

    i = j = 0;
    for (i = 0; from[i] != '\0'; i++)
    {
        if (from[i] == '\\')
        {
            switch (from[i + 1])
            {
            case 't':
                to[j++] = '\t';
                i++;
                break;
            case 'n':
                to[j++] = '\n';
                i++;
                break;
            default:
                to[j] = from[i];
                j++;
                break;
            }
        }
        else
        {
            to[j] = from[i];
            j++;
        }
    }
    to[j] = '\0';
}

int main()
{
    char *orig = "hello\tworld\nprogramming is\tfun";
    char escaped[MAXLINE];
    char unescaped[MAXLINE];

    printf("%s\n", orig);
    escape(escaped, orig);
    printf("%s\n", escaped);
    unescape(unescaped, escaped);
    printf("%s\n", unescaped);
}
