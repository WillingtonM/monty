#include "monty.h"

/**
  *func_sub- subtraction
  *@head: the stack head
  *@counter: the line number
  *Return: void
 */
void func_sub(stack_t **head, unsigned int counter)
{
	stack_t *aux_;
	int sus, n_node;

	aux_ = *head;
	for (n_node = 0; aux_ != NULL; n_node++)
		aux_ = aux_->next;

	if (n_node < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", counter);
		fclose(t_bus.file);
		free(t_bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	aux_ = *head;
	sus = aux_->next->n - aux_->n;
	aux_->next->n = sus;
	*head = aux_->next;
	free(aux_);
}
