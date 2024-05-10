#include <stdio.h>
#include <stdbool.h>

#define MAX_NESTING_DEPTH 1000
#define NORMAL 0
#define IN_COMMENT 1
#define IN_SINGLE_QUOTED_STRING 2
#define IN_DOUBLE_QUOTED_STRING 3

int error(int line_no, int col_no, int state, char *msg)
{
    printf("Line number: %d\n", line_no);
    printf("Col number: %d\n", col_no);
    printf("State: %d\n", state);
    printf("Error message: %s\n", msg);
    return 1;
}

int main()
{
    int c;
    bool escaped = false;
    int state = NORMAL;
    int stack[MAX_NESTING_DEPTH];
    int stack_ptr = 0;
    int col_no = 0;
    int line_no = 1;
    char err_msg[20];

    while ((c = getchar()) != EOF)
    {
        if (stack_ptr > MAX_NESTING_DEPTH)
        {
            printf("Max nesting depth exceeded: %d", MAX_NESTING_DEPTH);
            return 1;
        }

        // track line and column number
        col_no++;
        if (c == '\n')
        {
            line_no++;
            col_no = 0;
        }

        if (state == IN_SINGLE_QUOTED_STRING && c != '\'')
        {
            // noop
        }
        else if (state == IN_DOUBLE_QUOTED_STRING && c != '"')
        {
            // noop
        }
        else
        {
            // only track state of brackets if we are not in a quoted
            // string or comment
            if (c == '(' || c == '[' || c == '{')
            {
                stack[stack_ptr++] = c;
            }

            if (c == ')' && stack[--stack_ptr] != '(')
            {
                return error(line_no, col_no, state, "Parenthesis mismatch");
            }

            if (c == ']' && stack[--stack_ptr] != '[')
            {
                return error(line_no, col_no, state, "Square bracket mismatch");
            }

            if (c == '}' && stack[--stack_ptr] != '{')
            {
                return error(line_no, col_no, state, "Curly brace mismatch");
            }
        }

        // transition between quoted string and normal states, ignoring
        // escape sequences
        if (c == '\'')
        {
            if (state == IN_SINGLE_QUOTED_STRING && !escaped)
            {
                state = NORMAL;
            }
            else if (state == IN_DOUBLE_QUOTED_STRING) {
                // noop
            }
            else
            {
                state = IN_SINGLE_QUOTED_STRING;
            }
        }
        else if (c == '"')
        {
            if (state == IN_DOUBLE_QUOTED_STRING && !escaped)
            {
                state = NORMAL;
            }
            else if (state == IN_SINGLE_QUOTED_STRING) {
                // noop
            }
            else
            {
                state = IN_DOUBLE_QUOTED_STRING;
            }
        }

        if (c == '\\')
        {
            escaped = !escaped;
        }
        else
        {
            escaped = false;
        }
    }

    if (state == IN_SINGLE_QUOTED_STRING)
    {
        return error(line_no, col_no, state, "Expected closing '");
    }
    else if (state == IN_DOUBLE_QUOTED_STRING)
    {
        return error(line_no, col_no, state, "Expected closing \"");
    }

    if (stack_ptr > 0)
    {
        sprintf(err_msg, "Expected closing %c", stack[stack_ptr - 1]);
        return error(line_no, col_no, state, err_msg);
    }

    printf("No errors detected\n");
    return 0;
}
