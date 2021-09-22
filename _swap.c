#include "monty.h"
/**
 * swap - interchanges
 * @stack: pointer to double linked list
 * @line_nuber: current line number
 */
void _swap(stack_t **stack, unsigned int line_number __attribute__((unused)))
{	stack_t *tmp = *stack;

	if ((*stack)->next == NULL)
		_print_error("can't swap, stack too short", line_number);
	*(stack) = (*stack)->next;
	tmp->next = (*stack)->next;
	(*stack)->next = tmp;
	(*stack)->prev = NULL;
	tmp->prev = (*stack);
}
