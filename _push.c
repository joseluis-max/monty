#include "monty.h"
/**
 * push - push a item in stack or queue
 * @stack: pointer to double linked list
 * @line_nuber: current line number
 */
void _push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *node;
	unsigned int n;

        if (num == NULL)
		_print_error("push integer", line_number);
	n = (unsigned int)atoi(num);
	if (isdigit(n) || !n)
		_print_error("push integer", line_number);
	if (stack == NULL)
		exit(EXIT_FAILURE);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		free(node);
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = NULL;

	/* inset init */
	if (*stack != NULL)
	{
		(*stack)->prev = node;
		node->next = *stack;
	}
	*stack = node;
}
