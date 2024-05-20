#include <stdio.h>

int main()
{
    char n = -1;
    printf("%d\n", n);
    n = ~n;
    printf("%d\n", n);
    n = -2;
    printf("%d\n", n);
    n = ~n;
    printf("%d\n", n);
}
