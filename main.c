#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * main - code interpreter for monty
 * @argc: the number of arguments
 * @argv: file location of monty
 * Return: Returns 0 on success
 */
int main(int argc, char *argv[])
{
	char *cont;
	ssize_t read_line = 1;
	unsigned int count = 0;
	FILE *file_o;
	size_t size_o = 0;
	stack_t *stack = NULL;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file_o = fopen(argv[1], "r");
	bus.file = file_o;
	if (!file_o)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		cont = NULL;
		read_line = getline(&cont, &size_o, file_o);
		bus.content = cont;
		count++;
		if (read_line > 0)
		{
			exec(cont, &stack, count, file_o);
		}
		free(cont);
	}
	free_stack(stack);
	fclose(file_o);
	return (0);
}
