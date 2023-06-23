#include "monty.h"

/**
 * add_node - add node to head stack
 * @head: head of stack
 * @n: new value
 * Return: void
*/
void add_node(stack_t **head, int n)
{
	stack_t *n_node, *aux_;

	aux_ = *head;
	n_node = malloc(sizeof(stack_t));
	if (n_node == NULL)
	{ printf("Error\n");
		exit(0); }
	if (aux_)
		aux_->prev = n_node;
	n_node->n = n;
	n_node->next = *head;
	n_node->prev = NULL;
	*head = n_node;
}
