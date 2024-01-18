#include "my_header.h"

/**
 * my_push - add node to the stack
 * @stack: stack head
 * @line_number: line_number
 *
 * Return: no return
 */
void my_push(my_node_t **stack, unsigned int line_number)
{
	int number, j = 0, flag = 0;

	if (my_data.argument)
	{
		if (my_data.argument[0] == '-')
			j++;
		for (; my_data.argument[j] != '\0'; j++)
		{
			if (my_data.argument[j] > 57 || my_data.argument[j] < 48)
				flag = 1;
		}
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			free_all(stack);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage: push integer\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	number = atoi(my_data.argument);
	if (my_data.stack_flag == 0)
		my_add_node(stack, number);
	else
		my_add_queue(stack, number);
}

