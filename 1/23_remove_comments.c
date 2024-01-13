#include <stdio.h>

#define MAXLENGTH 1000
#define OUT 0
#define IN_SINGLE_LINE 1
#define IN_MULTI_LINE 2
#define LEAVING_MULTI_LINE 3

void print_program_without_comments(char line[], int lim);
int get_state(int current_state, char previous, char current);

int main()
{
    char buffer[MAXLENGTH];
    print_program_without_comments(buffer, MAXLENGTH);
}

void print_program_without_comments(char buffer[], int lim)
{
    int i;
    int c;
    int state;
    int previous;

    state = OUT;
    while ((c = getchar()) != EOF)
    {

        // enter a single-line comment
        if (state == OUT && previous == '/' && c == '/')
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

        else if (state == LEAVING_MULTI_LINE)
        {
            state = OUT;
        }

        // we are out of a comment with no transition
        else if (state == OUT)
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
