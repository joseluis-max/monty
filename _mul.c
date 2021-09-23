#include "monty.h"
/**
 * _mul - mul two nodes
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _mul(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *copy = (*stack)->next;
	stack_t *tmp = *stack;

	if ((*stack)->next == NULL)
	{
		_free_stack(*stack);
		free(tokens);
		free(line);
		fclose(stream);
		_print_error(": can't mul, stack too short", line_number);
	}
	copy->n = copy->n * (*stack)->n;
	copy->prev = NULL;
	*stack = copy;
	free(tmp);
}
