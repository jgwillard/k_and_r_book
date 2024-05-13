#include <stdio.h>
#include <limits.h>

int get_min_char()
{
    return ~(char)((unsigned char)~0 >> 1);
}

int get_max_char()
{
    return (char)((unsigned char)~0 >> 1);
}

int get_min_unsigned_char()
{
    return (unsigned char)0;
}

int get_max_unsigned_char()
{
    return (unsigned char)(~0);
}

int main()
{
    printf("Range of char: %d - %d\n", get_min_char(), get_max_char());
    printf("Range of unsigned char: %d - %d\n", get_min_unsigned_char(), get_max_unsigned_char());
}
