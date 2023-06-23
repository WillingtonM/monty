#include "monty.h"

/**
  *func_rotr- rotates stack to bottom
  *@head: the stack head
  *@counter: the line number
  *Return: void
 */
void func_rotr(stack_t **head, __attribute__((unused)) unsigned int counter)
{
	stack_t *cp;

	cp = *head;
	if (*head == NULL || (*head)->next == NULL)
		return;

	while (cp->next)
		cp = cp->next;

	cp->next = *head;
	cp->prev->next = NULL;
	cp->prev = NULL;
	(*head)->prev = cp;
	(*head) = cp;
}
