#include "monty.h"

/**
* exec - executes the opcode
* @stack: head linked list - stack
* @counter: line_counter
* @file: poiner to monty file
* @content: line content
* Return: no return
*/
int exec(char *content, stack_t **stack, unsigned int counter, FILE *file)
{
	instruction_t ops[] = {
				{"push", func_push}, {"pall", func_pall}, {"pint", func_pint},
				{"pop", func_pop},
				{"swap", func_swap},
				{"add", func_add},
				{"nop", func_nop},
				{"sub", func_sub},
				{"div", func_div},
				{"mul", func_mul},
				{"mod", func_mod},
				{"pchar", func_pchar},
				{"pstr", func_pstr},
				{"rotl", func_rotl},
				{"rotr", func_rotr},
				{"queue", func_queue},
				{"stack", func_stack},
				{NULL, NULL}
				};
	unsigned int j = 0;
	char *o;

	o = strtok(content, " \n\t");
	if (o && o[0] == '#')
		return (0);
	t_bus.arg = strtok(NULL, " \n\t");
	while (ops[j].opcode && o)
	{
		if (strcmp(o, ops[j].opcode) == 0)
		{	ops[j].f(stack, counter);
			return (0);
		}
		j++;
	}
	if (o && ops[j].opcode == NULL)
	{   fprintf(stderr, "L%d: unknown instruction %s\n", counter, o);
		fclose(file);
		free(content);
		free_stack(*stack);
		exit(EXIT_FAILURE); }
	return (1);
}
