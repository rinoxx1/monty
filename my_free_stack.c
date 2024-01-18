#include "my_header.h"

/**
 * my_free_stack - frees a doubly linked list
 * @stack: head of the stack
 */
void my_free_stack(my_node_t *stack)
{
	my_node_t *aux;

	aux = stack;
	while (stack)
	{
		aux = stack->next;
		free(stack);
		stack = aux;
	}
}
