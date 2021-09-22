#include "monty.h"
/**
 * _print_error_unknown - print error of command unknown
 * @msg: text message
 * @line: number line of error
 * @operation: command don't found
 */
void _print_error_unknown(char *msg, int line, char *operation)
{
	char *str_line;

	/* L<line_number>: unknown instruction <opcode> */
	str_line = _integer_to_string(line);
	write(STDERR_FILENO, "L", 1);
	write(STDERR_FILENO, str_line, strlen(str_line));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, msg, strlen(msg));
	write(STDERR_FILENO, ": ", 3);
	write(STDERR_FILENO, operation, strlen(operation));
	write(STDERR_FILENO, "\n", 1);
	free(str_line);
	exit(EXIT_FAILURE);
}
