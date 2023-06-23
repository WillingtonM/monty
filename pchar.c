#include "monty.h"

/**
 * func_pchar - prints the char at the top of the stack,
 * followed by a new line
 * @head: stack head
 * @counter: line_number
 * Return: no return
*/
void func_pchar(stack_t **head, unsigned int counter)
{
	stack_t *hd;

	hd = *head;
	if (!hd)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty\n", counter);
		fclose(t_bus.file);
		free(t_bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	if (hd->n > 127 || hd->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range\n", counter);
		fclose(t_bus.file);
		free(t_bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", hd->n);
}
