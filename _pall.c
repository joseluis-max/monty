#include "monty.h"
/**
 * _pall - print all stack
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *copy = *stack;

	while (copy)
	{
		printf("%d\n", copy->n);
		copy = copy->next;
	}
}
