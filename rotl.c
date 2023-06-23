#include "monty.h"

/**
  *func_rotl- rotates the stack to top
  *@head: the stack head
  *@counter: the line number
  *Return: void
 */
void func_rotl(stack_t **head,  __attribute__((unused)) unsigned int counter)
{
	stack_t *aux_, *tmp = *head;

	if (*head == NULL || (*head)->next == NULL)
		return;

	aux_ = (*head)->next;
	aux_->prev = NULL;
	while (tmp->next != NULL)
		tmp = tmp->next;
	tmp->next = *head;

	(*head)->next = NULL;
	(*head)->prev = tmp;
	(*head) = aux_;
}
