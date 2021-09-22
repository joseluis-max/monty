#ifndef _MONTY_H_
#define _MONTY_H_
#define  _GNU_SOURCE
/**
 * struct stack_s - doubly linked list representation of a stack (or queue)
 * @n: integer
 * @prev: points to the previous element of the stack (or queue)
 * @next: points to the next element of the stack (or queue)
 *
 * Description: doubly linked list node structure
 * for stack, queues, LIFO, FIFO
 */
typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
} stack_t;
/**
 * struct instruction_s - opcode and its function
 * @opcode: the opcode
 * @f: function to handle the opcode
 *
 * Description: opcode and its function
 * for stack, queues, LIFO, FIFO
 */
typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_number);
} instruction_t;
#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>
#include <string.h>
#include <aio.h>
#include <unistd.h>
extern char *num;
char **trim(char *s);
void _print_error(char *msg, unsigned int line);
int _strcmp(char *s1, char *s2);
char *_integer_to_string(int n);
void _free_stack(stack_t *stack);
void _print_error_unknown(char *msg, int line, char *operation);
void _push(stack_t **stack, unsigned int line_number __attribute__((unused)));
void _pall(stack_t **stack, unsigned int line_number __attribute__((unused)));
void _pint(stack_t **stack, unsigned int line_number __attribute__((unused)));
void _pop(stack_t **stack, unsigned int line_number __attribute__((unused)));
void _swap(stack_t **stack, unsigned int line_number __attribute__((unused)));
void _add(stack_t **stack, unsigned int line_number __attribute__((unused)));
void _nop(stack_t **stack, unsigned int line_number __attribute__((unused)));

#endif /* monty.h */
