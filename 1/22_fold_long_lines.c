#include <stdio.h>

#define FOLDLENGTH 59
#define IN 1
#define OUT 0

void print_folded_line(char line[], int count);

/**
 * Fold long input lines into two or more shorter lines after the last
 * non-blank character that occurs before the n-th column of input.
 */
int main()
{
    char buffer[FOLDLENGTH];
    print_folded_line(buffer, 0);
}

/**
 * Read input and print in a line until newline or FOLDLENGTH is
 * reached. If FOLDLENGTH is reached before newline, print everything up
 * to the current word on its own line, then print the current word and
 * the rest of the line on the next line.
 *
 * (base case)
 * When you reach a newline, reset character count, then print buffer.
 *
 * (recursive case)
 * If count reaches limit, reset count then back current buffer up to
 * beginning of current word. Create a new buffer and add current word
 * to it. Then call function with the new buffer and current index.
 */
void print_folded_line(char buffer[], int count)
{
    int i;
    int c;
    int state;
    int is_whitespace;
    int is_newline;
    int last_word_index;
    char new_buffer[FOLDLENGTH];

    state = OUT;
    while ((c = getchar()) != EOF)
    {
        is_whitespace = (c == ' ' || c == '\t');
        is_newline = c == '\n';
        buffer[count] = c;
        count++;

        // set states
        //
        // leaving word
        if (state == IN && is_whitespace)
        {
            last_word_index = count;
            state = OUT;
        }

        // entering word
        else if (state == OUT && !is_whitespace && !is_newline)
        {
            state = IN;
        }

        // base case
        if (is_newline)
        {
            buffer[count] = '\0';
            count = 0;
            printf("%s", buffer);
        }

        // recursive case
        else if (count > FOLDLENGTH)
        {
            // copy current word to new buffer
            for (i = 0; i < count - last_word_index; i++)
            {
                new_buffer[i] = buffer[last_word_index + i];
            }
            // terminate current buffer
            buffer[last_word_index - 1] = '\n';
            buffer[last_word_index] = '\0';
            printf("%s", buffer);
            print_folded_line(new_buffer, count - last_word_index);
        }
    }
}
