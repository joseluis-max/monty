#include "header.h"
/**
 * main - monty interpreter
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: EXIT_SUCCESS always
 */
int main(int argc, char *argv[])
{
	FILE *stream;
	char *line = NULL;
	size_t len = 0;
	ssize_t nread;
	int index;
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

	if (argc > 3 || argc < 0)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}

	stream = fopen(argv[1], "r");
	if (stream == NULL)
	{
		printf("Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (nread = getline(&line, &len, stream) != -1)
	{
		tokens = trim(line);
		index = 0;
		while (instructions[index].opcode)
		{
			if (strcmp(instructions[index].opcode, tokens[0]) == 0)
			{
				opcode = instructions[index].f;
				if (strcmp(tokens[0], "push") == 0)
				{
					opcode(&stack, (unsigned int)atoi(tokens[1]));
				}
				else
				{
					opcode(&stack, 0);
				}
			}
			index++;
		}
		free(tokens);
	}
	free(line);
	fclose(stream);
	return (0);
}
