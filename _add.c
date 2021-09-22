#include "monty.h"
/**
 * _add - add two nodes
 * @stack: pointer to double linked list
 * @line_number: current line number
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
