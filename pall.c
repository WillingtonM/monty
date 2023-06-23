#include "monty.h"
/**
 * func_pall - prints stack
 * @head: the stack head
 * @counter: counter
 * Return: void
*/
void func_pall(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	(void)counter;

	hd = *head;
	if (hd == NULL)
		return;
	while (hd)
	{
		printf("%d\n", hd->n);
		hd = hd->next;
	}
}
