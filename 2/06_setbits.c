#include <stdio.h>

/**
 * Returns the right-adjusted n-bit field of `x` that begins at position
 * `p`. Bit position `n` is at the right: 3 2 1 0
 *
 * For example, getbits(0x1c, 4, 3) returns the number containing the 3
 * bits in positions 4, 3, 2 shifted all the way to the right: 0x7.
 * Explanation: 0x1c = 0001 1100, 0x7 = 0000 0111
 */
unsigned getbits(unsigned x, int p, int n)
{
    return (x >> (p + 1 - n)) & ~(~0 << n);
}

/**
 * Returns `x` with the `n` bits that begin at position `p` set to the
 * rightmost `n` bits of `y`, leaving the other bits unchanged.
 *
 * Example: setbits(0xAA, 2, 3, 0x55) -> 0xAD
 * 1010 1010 (0xAA), 2, 3, 0101 0101 (0x55)
 * 1010 1101 (0xAD)
 */
unsigned setbits(unsigned x, int p, int n, unsigned y)
{
    // create a bitmask of n 1s starting from the rightmost position
    // (complement of 0 creates a number of all 1s, left shifting n
    // places will fill the rightmost n places with 0s, then taking the
    // complement of that number will give the desired bitmask)
    unsigned mask = ~(~0 << n);

    // zero out y except for the rightmost n bits
    y = mask & y;
    // left shift the rightmost n bits to start at position p
    y = y << ((p + 1) - n);

    // left shift the rightmost n bits of the bitmask to start at p
    mask = mask << ((p + 1) - n);
    // zero out the n bits starting at position p of x
    mask = ~mask;
    x = mask & x;

    return x | y;
}

int main()
{
    printf("%d\n", setbits(170, 2, 3, 85));  // -> 173
    printf("%d\n", setbits(255, 3, 2, 255)); // -> 255
    printf("%d\n", setbits(255, 3, 2, 0));   // -> 243
    printf("%d\n", setbits(255, 7, 8, 0));   // -> 0
    printf("%d\n", setbits(255, 7, 7, 0));   // -> 1
}
