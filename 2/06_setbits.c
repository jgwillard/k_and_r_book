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
    // TODO
}

int main()
{
    unsigned x = getbits(0x1c, 4, 3);
    printf("0x%x\n", x);
    unsigned y = getbits(0x18, 4, 3);
    printf("0x%x\n", y);
    unsigned z = getbits(0x14, 4, 3);
    printf("0x%x\n", z);
}
