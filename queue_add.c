#include "monty.h"

/**
 * add_queue - add node to tail stack
 * @n: the new value
 * @head: stack head
 * Return: void
 */
void add_queue(stack_t **head, int n)
{
	stack_t *n_node, *aux_;

	aux_ = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
		printf("Error\n");
	n_node->n = n;
	n_node->next = NULL;
	if (aux_)
	{
		while (aux_->next)
			aux_ = aux_->next;
	}
	if (!aux_)
	{
		*head = n_node;
		n_node->prev = NULL;
	}
	else
	{
		aux_->next = n_node;
		n_node->prev = aux_;
	}
}
