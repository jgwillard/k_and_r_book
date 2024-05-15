#include <stdio.h>
#include <limits.h>

/**
 * This macro defines a set of functions that return the minimum and
 * maximum values for a given type (signed and unsigned).
 *
 * get_min_type:
 *  Using the bitwise complement operator (~) on a value flips all the
 *  bits of that value. If that value is 0 then all bits will be flipped
 *  to 1. So we first create a value of the width of the type all of
 *  whose bits are 1 (~0). We then right shift (>>) all the bits by 1
 *  place. For example, an 8 bit value of 1111 1111 (0xFF) would be
 *  changed to 0111 1111 (0x7F). Finally, we take the complement of that
 *  value: 1000 0000 (0x80).
 *
 *  NOTE: In two's complement, if the most significant bit
 *  is 1 then the number is negative, so this represents the lowest
 *  possible value for a signed type, since the most significant bit is
 *  1 and all others are 0.
 *
 * get_max_type:
 *  Same as get_min_type except that we do not perform the final bitwise
 *  complement operation, so for an 8 bit value we get 0111 1111 (0x7F).
 *  Since the most significant bit is 0 and all others are 1, this is
 *  the highest possible value for a signed type.
 *
 * get_min_type_unsigned:
 *  This is trivial: for any unsigned type, the lowest possible value is
 *  0.
 *
 * get_max_type_unsigned:
 *  Here we just take the complement of the 0 value for the type. For an
 *  8 bit unsigned type, 0 is represented by 0000 0000 (0x00), and so
 *  its complement is 1111 1111 (0xFF).
 *
 */
#define MIN_MAX_FUNCS(type)                \
    int get_min_##type()                   \
    {                                      \
        return ~((unsigned type) ~0 >> 1); \
    }                                      \
    int get_max_##type()                   \
    {                                      \
        return ((unsigned type) ~0 >> 1);  \
    }                                      \
    int get_min_unsigned_##type()          \
    {                                      \
        return (unsigned type)0;           \
    }                                      \
    int get_max_unsigned_##type()          \
    {                                      \
        return (unsigned type)(~0);        \
    }

/**
 * These macros print the calculated ranges of each data type using the
 * functions defined above.
 */
#define PRINT_MIN_MAX(type) \
    printf("Actual range of " #type ":   %d -> %d\n", get_min_##type(), get_max_##type());

#define PRINT_MIN_MAX_UNSIGNED(type) \
    printf("Actual range of unsigned " #type ":   %u -> %u\n", get_min_unsigned_##type(), get_max_unsigned_##type());

MIN_MAX_FUNCS(char)
MIN_MAX_FUNCS(short)
MIN_MAX_FUNCS(int)

int main()
{
    printf("Expected range of char: %d -> %d\n", CHAR_MIN, CHAR_MAX);
    PRINT_MIN_MAX(char)
    printf("Expected range of unsigned char: %d -> %d\n", 0, UCHAR_MAX);
    PRINT_MIN_MAX_UNSIGNED(char)
    printf("\n");
    printf("Expected range of short: %d -> %d\n", SHRT_MIN, SHRT_MAX);
    PRINT_MIN_MAX(short)
    printf("Expected range of unsigned short: %d -> %d\n", 0, USHRT_MAX);
    PRINT_MIN_MAX_UNSIGNED(short)
    printf("\n");
    printf("Expected range of int: %d -> %d\n", INT_MIN, INT_MAX);
    PRINT_MIN_MAX(int)
    printf("Expected range of unsigned int: %u -> %u\n", 0, UINT_MAX);
    PRINT_MIN_MAX_UNSIGNED(int)
    printf("\n");
    // FIXME macros do not work for longs because (1) the return type
    // must be long not int and (2) the format specifiers must be
    // %ld/%lu not %d/%u
    printf("Expected range of long: %ld -> %ld\n", LONG_MIN, LONG_MAX);
    printf("Actual range of long:   %ld -> %ld\n", ~((unsigned long)~0 >> 1), ((unsigned long)~0 >> 1));
    printf("Expected range of unsigned long: %lu -> %lu\n", (long unsigned)0, ULONG_MAX);
    printf("Actual range of unsigned long:   %lu -> %lu\n", (unsigned long)0, (unsigned long)~0);
}
