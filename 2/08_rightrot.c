#include <stdio.h>

/**
 * Gets the size in bits of an integer in the system by calculating the
 * base-2 logarithm of the largest possible integer.
 */
int int_size()
{
    int i;
    // largest possible integer (cf. exercise 2-1)
    unsigned int n = ~0;
    for (i = 0; n >= 1; i++)
    {
        n /= 2;
    }
    return i;
}

/**
 * Returns the value of integer `x` rotated to the right by `n`
 * positions.
 */
unsigned rightrot(unsigned x, int n)
{
    // get number of bits in an integer
    int size = int_size();
    // bitmask of rightmost n bits
    unsigned mask = ~(~0 << n);
    // get the rightmost bits in x
    unsigned right_bits = mask & x;
    // shift rightmost n bits to leftmost position
    unsigned left_bits = right_bits << (size - n);
    // rotate
    x >>= n;
    // assign the former rightmost bits to the leftmost position
    return x |= left_bits;
}

int main()
{
    printf("0x%x\n", rightrot(0x1, 1)); // -> 0x80000000
    printf("0x%x\n", rightrot(0x3, 2)); // -> 0xc0000000
    printf("0x%x\n", rightrot(0x2, 1)); // -> 0x00000001
    printf("0x%x\n", rightrot(0xe, 4)); // -> 0xe0000000
}
