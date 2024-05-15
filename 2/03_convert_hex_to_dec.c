#include <stdio.h>
#include <string.h>

/**
 * Fast exponentiation
 * See https://stackoverflow.com/questions/213042/how-do-you-do-exponentiation-in-c
 * and SICP section 1.2.4
 */
int power(int base, int exponent)
{
    if (exponent == 0)
        return 1;
    else if (exponent % 2)
        return base * power(base, exponent - 1);
    else
    {
        int temp = power(base, exponent / 2);
        return temp * temp;
    }
}

/**
 * This function takes a string representing a hexadecimal number with
 * an optional `0x` or `0X` prefix and returns its value as an int. It
 * multiplies the value of the digit in each place by 16^(place - 1).
 * For example, the first (least significant) digit is multiplied by
 * 16^(1 - 1) = 16^0 = 1, the second digit is multiplied by 16^(2 - 1),
 * etc. The value of the digit is then added to the total value of the
 * number, which is returned when the whole string has been processed.
 */
int htoi(char s[])
{
    int i;
    int init = 0;
    int total = 0;
    int length = strlen(s);
    int place;
    int multiplier;
    // check for prefix and skip in main loop
    if (s[0] == '0' && (s[1] == 'x' || s[1] == 'X'))
    {
        init = 2;
    }
    // main loop
    for (i = init; s[i] != '\0'; i++)
    {
        place = length - i;
        multiplier = power(16, place - 1);
        if (s[i] >= '0' && s[i] <= '9')
        {
            total += (s[i] - '0') * multiplier;
        }
        else if (s[i] >= 'A' && s[i] <= 'F')
        {
            total += (s[i] - 'A' + 10) * multiplier;
        }
        else if (s[i] >= 'a' && s[i] <= 'f')
        {
            total += (s[i] - 'a' + 10) * multiplier;
        }
    }
    return total;
}

int main()
{
    printf("%d\n", htoi("0f"));
    printf("%d\n", htoi("0x0F"));
    printf("%d\n", htoi("ff"));
    printf("%d\n", htoi("0xff"));
    printf("%d\n", htoi("FF"));
    printf("%d\n", htoi("0xFF"));
    printf("%d\n", htoi("AB38"));
    printf("%d\n", htoi("ab38"));
    printf("%d\n", htoi("0xab38"));
    printf("%d\n", htoi("0Xab38"));
    printf("%d\n", htoi("0xAB38"));
}
