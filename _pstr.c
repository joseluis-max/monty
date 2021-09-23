#include "monty.h"
/**
 * _pstr - print string of the first node value
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _pstr(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *copy = *stack;

	if (stack != NULL || *stack != NULL)
	{
		while (copy)
		{
			if (copy->n >= 127 || copy->n <= 0)
				break;
			putchar(copy->n);
			copy = copy->next;
		}
	}
	putchar('\n');
}
