#include "monty.h"
/**
 * _pint - print top element in the stack
 * @stack: pointer to double linked list
 * @line_nuber: current line number
 */
void _pint(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	if (*stack == NULL)
		_print_error("can't pint, stack empty", line_number);
	printf("%d\n", (*stack)->n);
}
