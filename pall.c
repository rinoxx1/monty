#include "my_header.h"

/**
 * my_print_all - prints the stack
 * @stack: stack head
 * @line_number: not used
 *
 * Return: no return
 */
void my_print_all(my_node_t **stack, unsigned int line_number)
{
	my_node_t *current;

	(void)line_number;
	current = *stack;
	if (current == NULL)
		return;
	while (current)
	{
		printf("%d\n", current->data);
		current = current->next;
	}
}

