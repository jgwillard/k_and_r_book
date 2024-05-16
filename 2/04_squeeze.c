#include <stdio.h>
#include <stdbool.h>

void squeeze(char s1[], char s2[])
{
    int i, j, k;
    bool delete;

    for (i = j = 0; s1[i] != '\0'; i++)
    {
        delete = false;
        for (k = 0; s2[k] != '\0'; k++)
        {

            if (s1[i] == s2[k])
            {
                delete = true;
            }
        }
        if (!delete)
        {
            s1[j++] = s1[i];
        }
    }
    s1[j] = '\0';
}

int main()
{
    char s[] = "deleted";
    squeeze(s, "de");
    printf("%s\n", s);
    char s2[] = "abracadabra";
    squeeze(s2, "abc");
    printf("%s\n", s2);
}
