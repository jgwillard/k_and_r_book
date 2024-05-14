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

#define PRINT_MIN_MAX(type)                                                       \
    printf("Range of " #type ": %d -> %d\n", get_min_##type(), get_max_##type()); \
    printf("Range of unsigned " #type ": %u -> %u\n", get_min_unsigned_##type(), get_max_unsigned_##type());

MIN_MAX_FUNCS(char)
MIN_MAX_FUNCS(short)
MIN_MAX_FUNCS(int)

int main()
{
    PRINT_MIN_MAX(char)
    PRINT_MIN_MAX(short)
    PRINT_MIN_MAX(int)
    // FIXME macros do not work for longs because (1) the return type
    // must be long not int and (2) the format specifiers must be
    // %ld/%lu not %d/%u
    printf("Range of long: %ld -> %ld\n", ~((unsigned long)~0 >> 1), ((unsigned long)~0 >> 1));
    printf("Range of unsigned long: %lu -> %lu\n", (unsigned long)0, (unsigned long)~0);
}
