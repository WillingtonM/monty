#include "monty.h"

/**
 * func_div - divides top two elements of stack.
 * @head: stack head
 * @counter: the line number
 * Return: void
*/
void func_div(stack_t **head, unsigned int counter)
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
		fprintf(stderr, "L%d: can't div, stack too short\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	hd = *head;
	if (hd->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", counter);
		fclose(bus.file);
		free(bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}
	aux_ = hd->next->n / hd->n;
	hd->next->n = aux_;
	*head = hd->next;
	free(h);
}
