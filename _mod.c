#include "monty.h"
/**
 * _mod - module of two first nodes
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _mod(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *copy = (*stack)->next;
	stack_t *tmp = *stack;

	if ((*stack)->next == NULL)
	{
		_free_stack(*stack);
		free(tokens);
		free(line);
		fclose(stream);
		_print_error(": can't mod, stack too short", line_number);
	}
	if ((*stack)->n == 0)
	{
		_free_stack(*stack);
		free(tokens);
		free(line);
		fclose(stream);
		_print_error(": division by zero", line_number);
	}
	copy->n = copy->n % (*stack)->n;
	copy->prev = NULL;
	*stack = copy;
	free(tmp);
}
