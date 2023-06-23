#include "monty.h"

/**
 * func_pstr - prints string starting at the top of stack
 * @head: the stack head
 * @counter: the line number
 * Return: void
*/
void func_pstr(stack_t **head, unsigned int counter)
{
	stack_t *hd;
	(void)counter;

	hd = *head;
	while (hd)
	{
		if (hd->n > 127 || hd->n <= 0)
			break;

		printf("%c", hd->n);
		hd = hd->next;
	}

	printf("\n");
}
