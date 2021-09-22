#include "monty.h"
/**
 * _print_error - print error
 * @msg: text message
 * @line: number line of error
 */
void _print_error(char *msg, unsigned int line)
{
        char *str_line;

        str_line = _integer_to_string(line);
        write(STDERR_FILENO, "L", 1);
        write(STDERR_FILENO, str_line, strlen(str_line));
        write(STDERR_FILENO, ": usage: ", 10);
        write(STDERR_FILENO, msg, strlen(msg));
        write(STDERR_FILENO, "\n", 1);
        free(str_line);
        exit(EXIT_FAILURE);
}
