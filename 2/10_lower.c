#include <stdio.h>

int lower(int c)
{
    return (c >= 'A' && c <= 'Z') ? c + ('a' - 'A') : c;
}

int main()
{
    printf("%c\n", lower('A'));
    printf("%c\n", lower('B'));
    printf("%c\n", lower('c'));
    printf("%c\n", lower('x'));
    printf("%c\n", lower('Y'));
    printf("%c\n", lower('Z'));
    printf("%c\n", lower(';'));
}
