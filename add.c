#include "monty.h"

/**
 * func_add - adds top two elements of stack.
 * @head: stack head
 * @counter: line number
 * Return: void
 */
void func_add(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int length = 0, aux_;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", counter);
		fclose(t_bus.file);
		free(t_bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux_ = hd->n + hd->next->n;
	hd->next->n = aux_;
	*head = hd->next;
	free(hd);
}

