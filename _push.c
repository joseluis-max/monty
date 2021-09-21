#include "header.h"
/**
 * push - push a item in stack or queue
 * @
 * @
 * Return:
 */
void _push(stack_t **stack __attribute__((unused)), unsigned int num __attribute__((unused)))
{
	stack_t *node;
	
	if (stack == NULL)
		exit(EXIT_FAILURE);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		free(node);
		exit(EXIT_FAILURE);
	}
	node->n = num;
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
