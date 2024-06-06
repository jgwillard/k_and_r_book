#include <limits.h>
#include <stdio.h>
#include <string.h>

#define MAXLINE 100

/**
 * Reverses string `s` in place.
 */
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

/**
 * Converts `n` to characters in `s`.
 *
 * In a two's complement number representation, an implementation that
 * naively negates `n` will break on the most negative number, because
 * it is not possible to represent the negation of that number. For
 * example, in an eight-bit system, the highest positive number that can
 * be represented is 127, and the most negative number is -128. Its
 * negation 128, cannot be represented, and in fact the algorithm for
 * negating a number, when performed on the most negative number,
 * results in the same number (on my system INT_MIN == -INT_MIN). See
 * https://en.wikipedia.org/wiki/Two's_complement#Most_negative_number
 * for details.
 *
 * This implementation sovles the problem by checking whether `n` is the
 * most negative number and if it is, adding 1 to it so that it can be
 * negated, and then correcting the string representation after it has
 * been converted.
 */
void itoa(int n, char s[])
{
    int i;
    int sign;
    int most_neg_num = 0;

    // record sign
    sign = n;
    // if `n` is most negative number, make its negation representable
    // and record it
    if (n == INT_MIN)
    {
        n += 1;
        most_neg_num = 1;
    }
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

    // add back the digit that was taken away in order to make the most
    // negative number's negation representable
    if (most_neg_num)
    {
        s[0] = s[0] + 1;
    }

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

    char s1[MAXLINE];
    itoa(INT_MIN, s1);
    printf("%s\n", s1);

    char s2[MAXLINE];
    itoa(INT_MAX, s2);
    printf("%s\n", s2);
}
