#include "my_header.h"

/**
 * my_add - adds the top two elements of the stack.
 * @stack: stack head
 * @line_number: line_number
 * Return: no return
 */
void my_add(my_node_t **stack, unsigned int line_number)
{
	my_node_t *current;
	int len = 0, aux;

	current = *stack;
	while (current)
	{
		current = current->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L%d: can't add, stack too short\n", line_number);
		fclose(my_data.input_file);
		free(my_data.line_content);
		my_free_stack(*stack);
		exit(EXIT_FAILURE);
	}
	current = *stack;
	aux = current->data + current->next->data;
	current->next->data = aux;
	*stack = current->next;
	free(current);
}
