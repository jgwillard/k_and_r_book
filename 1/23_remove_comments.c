#include <stdio.h>

#define OUT 0
#define IN_SINGLE_LINE 1
#define IN_MULTI_LINE 2
#define LEAVING_MULTI_LINE 3
#define IN_QUOTED_STRING 4

int main()
{
    int c;
    int state;
    int previous;

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        // enter quoted string
        if (state == OUT && c == '"')
        {
            state = IN_QUOTED_STRING;
        }

        // leave quoted string
        else if (state == IN_QUOTED_STRING && c == '"')
        {
            state = OUT;
        }

        // enter a single-line comment
        else if (state == OUT && previous == '/' && c == '/')
        {
            state = IN_SINGLE_LINE;
        }

        // enter a multi-line comment
        else if (state == OUT && previous == '/' && c == '*')
        {
            state = IN_MULTI_LINE;
        }

        // leave single-line comment
        else if (state == IN_SINGLE_LINE && c == '\n')
        {
            state = OUT;
        }

        // leave multi-line comment
        else if (state == IN_MULTI_LINE && previous == '*' && c == '/')
        {
            state = LEAVING_MULTI_LINE;
        }

        // we have left multi-line comment
        // (ensure we don't print final '/')
        else if (state == LEAVING_MULTI_LINE)
        {
            state = OUT;
        }

        // we are out of a comment with no transition
        else if (state == OUT || state == IN_QUOTED_STRING)
        {
            putchar(previous);
        }

        previous = c;
    }

    if (state == OUT)
    {
        putchar(c);
    }

    putchar('\n');
}
