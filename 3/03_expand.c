#include <stdio.h>
#include <ctype.h>

#define MAXLINE 1000

/**
 * Expands shorthand notations like `a-z` in string `s1` into the
 * equivalent complete list `abc...xyz` in `s2`.
 */
void expand(char s1[], char s2[])
{
    int i;
    int j;
    char k;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        // dash at beginning of s1
        if (i == 0 && s1[i] == '-')
        {
            s2[j] = '-';
            j++;
        }
        // dash at end of s1
        else if (s1[i + 1] == '\0' && s1[i] == '-')
        {
            s2[j] = '-';
            j++;
        }
        else if (s1[i] == '-')
        {
            for (k = s1[i - 1]; k <= s1[i + 1]; k++)
            {
                s2[j] = k;
                j++;
            }
        }
        s2[j] = '\0';
    }
}

int main()
{
    char s1[MAXLINE];
    expand("a-z", s1);
    printf("%s\n", s1);

    char s2[MAXLINE];
    expand("A-Z", s2);
    printf("%s\n", s2);

    char s3[MAXLINE];
    expand("0-9", s3);
    printf("%s\n", s3);

    char s4[MAXLINE];
    expand("a-zA-Z", s4);
    printf("%s\n", s4);

    char s5[MAXLINE];
    expand("a-z0-9", s5);
    printf("%s\n", s5);

    char s6[MAXLINE];
    expand("a-b-c", s6);
    printf("%s\n", s6);

    char s7[MAXLINE];
    expand("-a-z", s7);
    printf("%s\n", s7);

    char s8[MAXLINE];
    expand("a-z-", s8);
    printf("%s\n", s8);
}
