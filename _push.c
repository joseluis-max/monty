#include "monty.h"
/**
 * _free - free memory
 * @stack: pointer to double linked list
 */
void _free(stack_t **stack)
{
	_free_stack(*stack);
	free(tokens);
	free(line);
	fclose(stream);
}
/**
 * _push - push a item in stack or queue
 * @stack: pointer to double linked list
 * @line_number: current line number
 */
void _push(stack_t **stack, unsigned int line_number __attribute__((unused)))
{
	stack_t *node;
	unsigned int n;
	int i = 0;

	if (num == NULL)
	{
		_free(stack);
		_print_error(": usage: push integer", line_number);
	}
	while (num[i] != '\0')
	{
		if (isdigit(num[i]) == 0 && num[0] !=  '-')
		{
			_free(stack);
			_print_error(": usage: push integer", line_number);
		}
		i++;
	}
	n = atoi(num);
	if (stack == NULL)
		exit(EXIT_FAILURE);
	node = malloc(sizeof(stack_t));
	if (node == NULL)
	{
		free(node);
		fprintf(stderr, "Error: malloc failed\n");
		exit(EXIT_FAILURE);
	}
	node->n = n;
	node->prev = NULL;
	node->next = NULL;
	if (*stack != NULL)
	{
		(*stack)->prev = node;
		node->next = *stack;
	}
	*stack = node;
}
