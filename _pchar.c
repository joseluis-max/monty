#include "monty.h"
/**
 * _pchar - print character of the first node value
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _pchar(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (stack == NULL || *stack == NULL)
	{
		_free_stack(*stack);
		free(tokens);
		free(line);
		fclose(stream);
		_print_error(": can't pchar, stack empty", line_number);
	}
	if ((*stack)->n >= 127 || (*stack)->n < 0)
	{
		_free_stack(*stack);
		free(tokens);
		free(line);
		fclose(stream);
		_print_error(": can't pchar, value out of range", line_number);
	}
	putchar((*stack)->n);
	putchar('\n');
}
