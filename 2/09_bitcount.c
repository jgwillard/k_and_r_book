#include <stdio.h>

/**
 * Counts the number of 1-bits in an integer.
 *
 * In a two's complement number system, `x &= (x - 1)` deletes the
 * rightmost 1-bit in `x`. In a binary number, the rightmost bit will be
 * either a 1 or a 0. In the case that the rightmost bit is 1, then
 * subtracting a 1 from the number will result in that bit being flipped
 * to 0: 1111 - 1 = 1110. Then if these numbers are ANDed together, in
 * the rightmost column 0 & 1 = 0, so the rightmost 1-bit is deleted:
 *
 *   1111
 * & 1110
 * ------
 *   1110
 *
 * In the case that the rightmost bit is 0, then subtracting 1 from the
 * number will result in the rightmost 1-bit being flipped to 0 and the
 * 0-bit to its right being flipped to 1: 1110 - 1 = 1101. Then if these
 * numbers are ANDed together, in the column with the rightmost 1-bit,
 * 1 & 0 = 0, and in the column to the right of that, 0 & 1 = 0, so the
 * rightmost 1-bit is deleted:
 *
 *   1110
 * & 1101
 * ------
 *   1100
 *
 * This fact can be used to implement a faster version of bitcount than
 * the following:
 *
 * for (b = 0; x != 0; x >>= 1)
 * {
 *   if (x & 01)
 *   {
 *      b++;
 *   }
 * }
 * return b;
 *
 * The above implementation of bitcount will execute the body of the for
 * loop once for every bit in its integer argument whereas this version
 * will only execute the body of the for loop once for every 1-bit in
 * the argument.
 */
int bitcount(unsigned x)
{
    int b;

    for (b = 0; x != 0; x &= (x - 1))
    {
        b++;
    }
    return b;
}

int main()
{
    printf("%d\n", bitcount(0));  // -> 0
    printf("%d\n", bitcount(1));  // -> 1
    printf("%d\n", bitcount(2));  // -> 1
    printf("%d\n", bitcount(3));  // -> 2
    printf("%d\n", bitcount(15)); // -> 4
    printf("%d\n", bitcount(-1)); // -> 32
    printf("%d\n", bitcount(-2)); // -> 31
}
