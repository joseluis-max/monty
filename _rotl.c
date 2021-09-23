#include "monty.h"
/**
 * _rotl- move top item to the end
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _rotl(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp, *node;

	if (stack == NULL || *stack == NULL)
	{
		return;
	}
	if ((*stack)->next == NULL)
	{
		return;
	}
	tmp = *stack;
	(*stack) = (*stack)->next;
	(*stack)->prev = NULL;
	tmp->next = NULL;
	node = *stack;
	while (node->next)
		node = node->next;
	tmp->prev = node;
	node->next = tmp;
}
