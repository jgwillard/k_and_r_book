#include <stdio.h>

/**
 * Returns `x` with the `n` bits that begin at position `p` inverted,
 * leaving the other bits unchanged.
 *
 * Example: invert(0x55, 3, 2) -> 0x59
 * 0101 0101 (0x55), 3, 2
 * 0101 1001 (0x59)
 */
unsigned invert(unsigned x, int p, int n)
{
    unsigned inverted;
    unsigned remaining;
    // create a bitmask of n 1s starting at bit 0 and left shift such
    // that it starts at position p
    unsigned mask = (~(~0 << n)) << (p + 1 - n);

    // mask & x gets the target bits, the complement of the target bits
    // inverts them, and ANDing with the mask again zeroes out all other
    // bits
    inverted = ~(mask & x) & mask;

    // ANDing x with the complement of the mask gets the bits that are
    // not to be inverted, with the rest zeroed out
    remaining = ~mask & x;

    // since all the bits from the original number of `inverted` are
    // zeroed out in `remaining` and vice versa, ORing them together
    // will result in the original number with n bits starting at
    // position p inverted
    return inverted | remaining;
}

int main()
{
    printf("0x%x\n", invert(0x55, 3, 4)); // -> 0x5a
    printf("0x%x\n", invert(0x55, 3, 2)); // -> 0x59
    printf("0x%x\n", invert(0x55, 1, 2)); // -> 0x56
}
