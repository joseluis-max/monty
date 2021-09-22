#include "monty.h"
/**
 * add - add two nodes
 * @stack:
 * @num:
 */
void _add(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *copy = (*stack)->next;
	stack_t *tmp = *stack;

	if ((*stack)->next == NULL)
		_print_error("can't add, stack too short", line_number);
	copy->n = (*stack)->n + copy->n;
	copy->prev = NULL;
	*stack = copy;
	free(tmp);

}
