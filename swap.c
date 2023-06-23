#include "monty.h"

/**
 * func_swap - adds the top two elements of stack.
 * @head: the stack head
 * @counter: the line number
 * Return: void
*/
void func_swap(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	int aux_, length = 0;

	hd = *head;
	while (hd)
	{
		hd = hd->next;
		length++;
	}

	if (length < 2)
	{
		fprintf(stderr, "L%d: can't swap, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	hd = *head;
	aux_ = hd->n;
	hd->n = hd->next->n;
	hd->next->n = aux_;
}
