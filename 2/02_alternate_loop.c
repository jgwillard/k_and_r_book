#include <stdio.h>

/**
 * Write the equivalent of the following for loop without using `&&` or
 * `||`:
 *
 *  for (i = 0; i < lim - 1 && (c = getchar()) != '\n' && c != EOF; ++i)
 *
 */
int main()
{
    int i;
    int lim = 10;
    char c;

    i = 0;
    while ((c = getchar()))
    {
        if (c == '\n')
        {
            break;
        }
        else if (c == EOF)
        {
            break;
        }

        if (i++ >= lim - 1)
        {
            break;
        }

        putchar(c);
    }
    putchar('\n');
}
