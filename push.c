#include "monty.h"

/**
 * func_push - add node to stack
 * @head: the stack head
 * @counter: the line number
 * Return: void
*/
void func_push(stack_t **head, unsigned int counter)
{
	int node, flag = 0, k = 0;

	if (t_bus.arg)
	{
		if (t_bus.arg[0] == '-')
			k++;
		for (; t_bus.arg[k] != '\0'; k++)
		{
			if (t_bus.arg[k] > 57 || t_bus.arg[k] < 48)
			{
				flag = 1;
			}
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", counter);
			fclose(t_bus.file);
			free(t_bus.content);
			free_stack(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{ fprintf(stderr, "L%d: usage: push integer\n", counter);
		fclose(t_bus.file);
		free(t_bus.content);
		free_stack(*head);
		exit(EXIT_FAILURE);
	}

	node = atoi(t_bus.arg);
	if (t_bus.lifi == 0)
		add_node(head, node);
	else
		add_queue(head, node);
}
