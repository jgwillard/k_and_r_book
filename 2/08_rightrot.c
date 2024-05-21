#include <stdio.h>

/**
 * Gets the size of an integer in the system by calculating the base-2
 * logarithm of the largest possible integer.
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
 * TODO test and document
 */
unsigned rightrot(unsigned x, int n)
{
    int size = int_size();
    // bitmask of rightmost n bits
    unsigned mask = ~(~0 << n);
    unsigned right_bits = mask & x;
    // shift rightmost n bits to leftmost position
    unsigned left_bits = right_bits << (size - n);
    // rotate
    x = x >> n;
    // assign the former rightmost bits to the leftmost position
    return x |= left_bits;
}

int main()
{
    printf("0x%x\n", rightrot(1, 1));
}
