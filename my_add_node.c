#include "my_header.h"
#include "my_header.h"

/**
 * my_add_node - add node to the head stack
 * @stack: head of the stack
 * @data: new_value
 * Return: no return
 */
void my_add_node(my_node_t **stack, int data)
{
	my_node_t *new_node, *current;

	current = *stack;
	new_node = malloc(sizeof(my_node_t));
	if (new_node == NULL)
	{
		fprintf(stderr, "Error\n");
		exit(EXIT_FAILURE);
	}
	if (current)
		current->prev = new_node;
	new_node->data = data;
	new_node->next = *stack;
	new_node->prev = NULL;
	*stack = new_node;
}
