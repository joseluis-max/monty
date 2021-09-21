#include "header.h"
/**
 * _pint - print top element in the stack
 * @stack:
 * @num:
 */
void _pint(stack_t **stack __attribute__((unused)), unsigned int num __attribute__((unused)))
{
	if (*stack == NULL)
	{
		printf("L<line_number>: can't pint, stack empty\n");
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->n);
}
