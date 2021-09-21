#include "header.h"
/**
 * pall - print all stack
 * @stack: stack
 */
void _pall(stack_t **stack __attribute__((unused)), unsigned int num __attribute__((unused)))
{
	stack_t *copy = *stack;

	while (copy)
	{
		printf("%d\n", copy->n);
		copy = copy->next;
	}
}
