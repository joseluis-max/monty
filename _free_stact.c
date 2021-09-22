#include "monty.h"
/**
 * free_dlistint - free double linked lists
 * @stack: pointer double linked list
 */
void _free_stack(stack_t *stack)
{
        stack_t *tmp;

	while (stack)
	{
		tmp = stack;
		stack = stack->next;
		free(tmp);
	}
}
