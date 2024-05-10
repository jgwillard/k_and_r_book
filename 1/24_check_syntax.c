#include <stdio.h>
#include <stdbool.h>

#define MAX_NESTING_DEPTH 1000
#define NORMAL 0
#define IN_COMMENT 1
#define IN_SINGLE_QUOTED_STRING 2
#define IN_DOUBLE_QUOTED_STRING 3

int error(int line_no, int col_no, int mode, char *msg)
{
    printf("Line number: %d\n", line_no);
    printf("Col number: %d\n", col_no);
    printf("mode: %d\n", mode);
    printf("Error message: %s\n", msg);
    return 1;
}

int main()
{
    int c;
    bool escaped = false;
    int mode = NORMAL;
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

        // transition between quoted string and normal modes, ignoring
        // escape sequences

        // if we are in single quoted string mode and we encounter any
        // character other than a single quote, do nothing
        if (mode == IN_SINGLE_QUOTED_STRING && c != '\'')
        {
            // noop
        }
        // if we are in double quoted string mode and we encounter any
        // character other than a double quote, do nothing
        else if (mode == IN_DOUBLE_QUOTED_STRING && c != '"')
        {
            // noop
        }
        // if we encounter a single quote in any mode, then:
        //      if we are in single quote mode, transition to normal mode
        //      if we are in double quote mode, ignore
        //      if we are in normal mode, transition to single quote mode
        else if (c == '\'')
        {
            if (mode == IN_SINGLE_QUOTED_STRING && !escaped)
            {
                mode = NORMAL;
            }
            else if (mode == IN_DOUBLE_QUOTED_STRING) {
                // noop
            }
            else if (mode == NORMAL)
            {
                mode = IN_SINGLE_QUOTED_STRING;
            }
        }
        // if we encounter a double quote in any mode, then:
        //      if we are in double quote mode, transition to normal mode
        //      if we are in single quote mode, ignore
        //      if we are in normal mode, transition to double quote mode
        else if (c == '"')
        {
            if (mode == IN_DOUBLE_QUOTED_STRING && !escaped)
            {
                mode = NORMAL;
            }
            else if (mode == IN_SINGLE_QUOTED_STRING) {
                // noop
            }
            else
            {
                mode = IN_DOUBLE_QUOTED_STRING;
            }
        }
        // handle all other characters in normal mode
        else
        {
            // push any opening brackets onto the stack
            if (c == '(' || c == '[' || c == '{')
            {
                stack[stack_ptr++] = c;
            }

            // if we encounter any closing brackets, pop stack and check
            if (c == ')' && stack[--stack_ptr] != '(')
            {
                return error(line_no, col_no, mode, "Parenthesis mismatch");
            }

            if (c == ']' && stack[--stack_ptr] != '[')
            {
                return error(line_no, col_no, mode, "Square bracket mismatch");
            }

            if (c == '}' && stack[--stack_ptr] != '{')
            {
                return error(line_no, col_no, mode, "Curly brace mismatch");
            }
        }

        // manage escaped state
        if (c == '\\')
        {
            escaped = !escaped;
        }
        else
        {
            escaped = false;
        }
    }

    if (mode == IN_SINGLE_QUOTED_STRING)
    {
        return error(line_no, col_no, mode, "Expected closing '");
    }
    else if (mode == IN_DOUBLE_QUOTED_STRING)
    {
        return error(line_no, col_no, mode, "Expected closing \"");
    }

    if (stack_ptr > 0)
    {
        sprintf(err_msg, "Expected closing %c", stack[stack_ptr - 1]);
        return error(line_no, col_no, mode, err_msg);
    }

    printf("No errors detected\n");
    return 0;
}
