#include "monty.h"
/**
 * _pint - print top element in the stack
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	char *str;

	if (*stack == NULL)
	{
		_free_stack(*stack);
		free(tokens);
		free(line);
		fclose(stream);
		_print_error(": can't pint, stack empty", line_number);
	}
	str = _integer_to_string((*stack)->n);
	write(STDOUT_FILENO, str, strlen(str));
	write(STDOUT_FILENO, "\n", 2);
	free(str);
}
