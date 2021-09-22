#include "monty.h"
/**
 * trim - delete spaces in a string
 * @s: string for clean
 * Return: string without spaces
 */
char **trim(char *s)
{
	char **tokens;
	char *token;
	int index;

	tokens = malloc(20 * sizeof(char *));
	if (tokens == NULL)
	{
		free(tokens);
		exit(EXIT_FAILURE);
	}
	token = strtok(s, " \n\r\t\a");
	index = 0;
	while (token != NULL)
	{
		tokens[index] = token;
		token = strtok(NULL, " \n\r\t\a");
		index++;
	}
	tokens[index] = NULL;
	return (tokens);
}
