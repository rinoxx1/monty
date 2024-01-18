#include "my_header.h"

/**
 * my_print_int - prints the top
 * @stack: stack head
 * @line_number: line_number
 *
 * Return: no return
 */
void my_print_int(my_node_t **stack, unsigned int line_number)
{
	if (*stack == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		free_all(stack);
		exit(EXIT_FAILURE);
	}
	printf("%d\n", (*stack)->data);
}

