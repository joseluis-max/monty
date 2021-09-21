#include "header.h"
/**
 * add - add two nodes
 * @stack:
 * @num:
 */
void _add(stack_t **stack __attribute__((unused)), unsigned int num __attribute__((unused)))
{
	stack_t *copy = (*stack)->next;
	stack_t *tmp = *stack;

	if ((*stack)->next == NULL)
	{
		printf("L<line_number>: can't add, stack too short");
		exit(EXIT_FAILURE);
	}
	copy->n = (*stack)->n + copy->n;
	copy->prev = NULL;
	*stack = copy;
	free(tmp);

}
