#include "my_header.h"

/**
 * my_pop - prints the top
 * @stack: stack head
 * @line_number: line_number
 *
 * Return: no return
 */
void my_pop(my_node_t **stack, unsigned int line_number)
{
	my_node_t *current;

	if (*stack == NULL)
	{
		fprintf(stderr, "L%d: can't pop an empty stack\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	*stack = current->next;
	free(current);
}

