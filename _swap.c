#include "header.h"
/**
 * swap - interchanges
 * @stack:
 * @num:
 */
void _swap(stack_t **stack __attribute__((unused)), unsigned int num __attribute__((unused)))
{	stack_t *tmp = *stack;

	if ((*stack)->next == NULL)
	{
		printf("L<line_number>: can't swap, stack too short");
		exit(EXIT_FAILURE);
	}
	*(stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = (*stack);
}
