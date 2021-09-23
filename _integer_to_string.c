#include "monty.h"
/**
 * _integer_to_string - convert int to string
 * @n: int for convert
 * Return: string of int n
 */
char *_integer_to_string(int n)
{
	int div;
	unsigned int num;
	char *buffer;
	int digit  = 1;
	int i = 0;

	div = 1;
	num = n;
	while (num / div > 9)
	{
		div *= 10;
		digit++;
	}
	buffer = malloc(sizeof(char) * digit + 1);
	if (buffer == NULL)
	{
		fprintf(STDERR_FILENO, "Error: malloc failed\n");
		free(buffer);
		exit(EXIT_FAILURE);
	}
	while (div > 0)
	{
		buffer[i] = '0' + (num / div);
		num %= div;
		div /= 10;
		i++;
	}
	buffer[i] = '\0';
	return (buffer);
}
