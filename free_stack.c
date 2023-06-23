#include "monty.h"

/**
 * free_stack - frees doubly linked list
 * @head: head of stack
 * Return: void
 */
void free_stack(stack_t *head)
{
	stack_t *aux_;

	aux_ = head;
	while (head)
	{
		aux_ = head->next;
		free(head);
		head = aux_;
	}
}
