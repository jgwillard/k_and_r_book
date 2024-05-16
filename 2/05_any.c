#include <stdio.h>

/**
 * Return the first location in the string `s1` where any character from
 * the string `s2` occurs, or -1 if `s1` contains no characters from
 * `s2`.
 */
int any(char s1[], char s2[])
{
    int i, j;

    for (i = 0; s1[i] != '\0'; i++)
    {
        for (j = 0; s2[j] != '\0'; j++)
        {
            if (s1[i] == s2[j])
            {
                return i;
            }
        }
    }
    return -1;
}

int main()
{
    char s[] = "yesterday";
    char charset[] = "xz";
    printf("%d\n", any(s, charset));
    char s2[] = "abcdefg";
    char charset2[] = "gf";
    printf("%d\n", any(s2, charset2));
}
