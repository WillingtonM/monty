#include "monty.h"

/**
 * func_mul - multiplies top two elements of stack.
 * @head: the stack head
 * @counter: the line number
 * Return: void
*/
void func_mul(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't mul, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	aux_ = hd->next->n * hd->n;
	hd->next->n = aux_;
	*head = hd->next;
	free(hd);
}
