#include "monty.h"
/**
 * _pop - pop
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _pop(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *tmp;

	if (*stack == NULL)
	{
		_free_stack(*stack);
		free(tokens);
		free(line);
		fclose(stream);
		_print_error(": can't pop an empty stack", line_number);
	}
	tmp = *stack;
	(*stack) = (*stack)->next;
	if (*stack != NULL)
	{
		(*stack)->prev = NULL;
	}
	free(tmp);
}
