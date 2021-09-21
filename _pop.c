#include "header.h"
/**
 * pop - pop
 * @stack:
 * @num:
 */
void _pop(stack_t **stack __attribute__((unused)), unsigned int num __attribute__((unused)))
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		printf("L<line_number>: can't pop an empty stack\n");
		exit(EXIT_FAILURE);
	}

	tmp = *stack;
	(*stack) = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}
