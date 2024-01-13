#include <stdio.h>

#define MAX_NESTING_DEPTH 1000

int main()
{
    int c;
    int stack[MAX_NESTING_DEPTH];
    int stack_ptr = 0;

    while ((c = getchar()) != EOF)
    {
        if (c == '(' || c == '[' || c == '{')
        {
            stack[stack_ptr++] = c;
        }

        if (c == ')' && stack[--stack_ptr] != '(')
        {
            printf("Error detected: %c\n", c);
            return 1;
        }

        if (c == ']' && stack[--stack_ptr] != '[')
        {
            printf("Error detected: %c\n", c);
            return 1;
        }

        if (c == '}' && stack[--stack_ptr] != '{')
        {
            printf("Error detected: %c\n", c);
            return 1;
        }
    }

    if (stack_ptr > 0)
    {
        printf("Error detected: %c\n", stack[stack_ptr]);
        return 1;
    }
}
