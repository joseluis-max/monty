#include "monty.h"
char **tokens;
char *num;
FILE *stream;
char *line = NULL;
/**
 * _print_error_file - print error file
 * @file: file name
 */
void _print_error_file(char *file)
{
	write(STDERR_FILENO, "Error: Can't open file ", 24);
	write(STDERR_FILENO, file, strlen(file));
	write(STDERR_FILENO, "\n", 1);
	/* fclose(stream); */
	exit(EXIT_FAILURE);
}
/**
 * find_operation - macth command and operation
 * @line_counter: current line content
 * @line_counter: curren line number
 * @stack: header of double linked list
 * @command: operation
 * Return: status
 */
int find_operation(int line_counter, stack_t **stack, char *command)
{
	int index = 0;
	void (*opcode)(stack_t **stack, unsigned int num);
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{"sub", _sub},
		{"div", _div},
		{"mul", _mul},
		{"mod", _mod},
		{"pchar", _pchar},
		{"pstr", _pstr},
		{"rotl", _rotl},
		{"rotr", _rotr},
		{NULL, NULL}
	};

	while (instructions[index].opcode)
	{
		if (strcmp(instructions[index].opcode, command) == 0)
		{
			opcode = instructions[index].f;
			opcode(stack, line_counter);
			return (1);
		}
		index++;
	}
	return (0);
}
/**
 * main - monty interpreter
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: EXIT_SUCCESS always
 */
int main(int argc, char *argv[])
{
	size_t len = 0;
	ssize_t nread;
	int status = 0, line_counter = 0;
	stack_t *stack = NULL;

	if (argc > 2 || argc < 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 18);
		exit(EXIT_FAILURE);
	}
	stream = fopen(argv[1], "r");
	if (stream == NULL)
		_print_error_file(argv[1]);
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		line_counter++;
		tokens = trim(line);
		if (tokens[0] == NULL || tokens[2] != NULL)
		{
			free(tokens);
			continue;
		}
		num = tokens[1];
		if (strcmp(tokens[0], "#") == 0 || strncmp(tokens[0], "#", 1) == 0)
		{
			free(tokens);
			continue;
		}
		status = find_operation(line_counter, &stack, tokens[0]);
		if (status == 0)
		{
			_free_stack(stack);
			fclose(stream);
			_print_error_unknown("unknown instruction", line_counter, tokens[0]);
		}
		free(tokens);
	}
	free(line);
	_free_stack(stack);
	fclose(stream);
	return (0);
}
