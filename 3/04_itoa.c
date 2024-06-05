#include <stdio.h>
#include <string.h>

#define MAXLINE 100

void reverse(char s[])
{
    int c;
    int i;
    int j;

    for (i = 0, j = strlen(s) - 1; i < j; i++, j--)
    {
        c = s[i];
        s[i] = s[j];
        s[j] = c;
    }
}

void itoa(int n, char s[])
{
    int i;
    int sign;

    // record sign
    sign = n;
    // make n positive
    if (n < 0)
    {
        n = -n;
    }

    i = 0;
    // generate digits in reverse order
    do
    {
        // get next digit
        s[i++] = n % 10 + '0';
        // delete it
    } while ((n /= 10) > 0);

    if (sign < 0)
    {
        s[i++] = '-';
    }
    s[i] = '\0';
    reverse(s);
}

int main()
{
    char s[MAXLINE];
    itoa(-1234, s);
    printf("%s\n", s);
}
