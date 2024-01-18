#include "monty.h"

/**
 * new_push - adds a node to the stack
 * @stack: stack head
 * @line_num: line number
 *
 * Return: void
 */
void new_push(stack_t **stack, unsigned int line_num)
{
	int number, index = 0, invalid_flag = 0;

	if (bus.modified_arg)
	{
		if (bus.modified_arg[0] == '-')
			index++;
		for (; bus.modified_arg[index] != '\0'; index++)
		{
			if (bus.modified_arg[index] > 57 || bus.modified_arg[index] < 48)
				invalid_flag = 1;
		}
		if (invalid_flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_num);
			free_all(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_num);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	number = atoi(bus.modified_arg);
	if (bus.modified_lifi == 0)
		new_add_node(stack, number);
	else
		add_queue(stack, number);
}

#include "modified_monty.h"

/**
 * new_pall - prints the entire stack
 * @stack: stack head
 * @line_num: not used
 *
 * Return: void
 */
void new_pall(stack_t **stack, unsigned int line_num)
{
	stack_t *h;

	(void)line_num;
	h = *stack;
	if (h == NULL)
		return;
	while (h)
	{
		printf("%d\n", h->n);
		h = h->next;
	}
}
