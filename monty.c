#include "header.h"
/**
 * main - monty interpreter
 * @argc: number of arguments
 * @argv: list of arguments
 * Return: EXIT_SUCCESS always
 */
int main(int argc, char *argv[])
{
	if (argc > 2 || argc < 2)
	{
		printf("USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	return (0);
}
