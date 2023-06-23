#include "monty.h"

/**
 * func_pop - prints the top
 * @head: the stack head
 * @counter: the line number
 * Return: void
*/
void func_pop(stack_t **head, unsigned int counter)
{
	stack_t *hd;

	if (*head == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	*head = hd->next;
	free(hd);
}
