#include <stdio.h>
#include <limits.h>

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

#define PRINT_MIN_MAX(type) \
    printf("Actual range of " #type ": %d -> %d\n", get_min_##type(), get_max_##type());

#define PRINT_MIN_MAX_UNSIGNED(type) \
    printf("Actual range of unsigned " #type ": %u -> %u\n", get_min_unsigned_##type(), get_max_unsigned_##type());

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
    printf("Expected range of unsigned int: %d -> %d\n", 0, UINT_MAX);
    PRINT_MIN_MAX_UNSIGNED(int)
    printf("\n");
    // FIXME macros do not work for longs because (1) the return type
    // must be long not int and (2) the format specifiers must be
    // %ld/%lu not %d/%u
    printf("Expected range of long: %ld -> %ld\n", LONG_MIN, LONG_MAX);
    printf("Actual range of long: %ld -> %ld\n", ~((unsigned long)~0 >> 1), ((unsigned long)~0 >> 1));
    printf("Expected range of unsigned int: %lu -> %lu\n", (long unsigned)0, ULONG_MAX);
    printf("Actual range of unsigned long: %lu -> %lu\n", (unsigned long)0, (unsigned long)~0);
}
