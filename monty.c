#include "monty.h"
/**
 * main - monty interpreter
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: EXIT_SUCCESS always
 */
char *num;

int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int index, status = 0, line_counter = 1;
	void (*opcode)(stack_t **stack, unsigned int num);
	char **tokens;
	stack_t *stack = NULL;
	instruction_t instructions[] = {
		{"push", _push},
		{"pall", _pall},
		{"pint", _pint},
		{"pop", _pop},
		{"swap", _swap},
		{"add", _add},
		{"nop", _nop},
		{NULL, NULL}
	};

	if (argc > 2 || argc < 2)
	{
		write(STDERR_FILENO, "USAGE: monty file\n", 19);
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		write(STDERR_FILENO, "Error: Can't open file ", 24);
		write(STDERR_FILENO, argv[1], strlen(argv[1]));
		write(STDERR_FILENO, "\n", 1);
		exit(EXIT_FAILURE);
	}
	while ((nread = getline(&line, &len, stream)) != -1)
	{
		tokens = trim(line);
		num = tokens[1];
		index = 0;
		while (instructions[index].opcode)
		{
			if (strcmp(instructions[index].opcode, tokens[0]) == 0)
			{
				opcode = instructions[index].f;
				opcode(&stack, line_counter);
				status = 1;
			}
			index++;
		}
		if (status == 0)
			_print_error_unknown("unknown instruction", line_counter, tokens[0]);
		line_counter++;
		free(tokens);
	}
	free(line);
	_free_stack(stack);
	fclose(stream);
	return (0);
}
