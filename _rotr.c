#include "monty.h"
/**
 * _rotr- move bottom item to the top
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _rotr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *node;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	if ((*stack)->next == NULL)
	{
		return;
	}

	node = *stack;
	while (node->next)
		node = node->next;
	(*stack)->prev = node;
	node->next = *stack;
	node->prev->next = NULL;
	node->prev = NULL;
	*stack = node;
}
