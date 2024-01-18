#ifndef MY_HEADER_H
#define MY_HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

/**
 * struct my_node - node structure
 * @data: data
 * @prev: pointer to previous node
 * @next: pointer to next node
 */
typedef struct my_node
{
	int data;
	struct my_node *prev;
	struct my_node *next;
} my_node_t;

/**
 * struct my_data - data structure
 * @argument: argument
 * @input_file: input file
 * @line_content: line content
 * @stack_flag: stack flag
 */
typedef struct my_data
{
	char *argument;
	FILE *input_file;
	char *line_content;
	int stack_flag;
} my_data_t;

extern my_data_t my_data;

/**
 * struct my_instruction - instruction structure
 * @opcode: opcode
 * @function: function
 */
typedef struct my_instruction
{
	char *opcode;
	void (*function)(my_node_t **stack, unsigned int line_number);
} my_instruction_t;

char *my_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t my_getstdin(char **lineptr, int file);
char *my_clean_line(char *content);
void my_push(my_node_t **stack, unsigned int line_number);
void my_print_all(my_node_t **stack, unsigned int line_number);
void my_print_int(my_node_t **stack, unsigned int line_number);
int my_execute(char *content, my_node_t **stack, unsigned int counter, FILE *file);
void my_free_stack(my_node_t *stack);
void my_pop(my_node_t **stack, unsigned int counter);
void my_swap(my_node_t **stack, unsigned int counter);
void my_add(my_node_t **stack, unsigned int counter);
void my_nop(my_node_t **stack, unsigned int counter);
void my_add_node(my_node_t **stack, int data);

#endif
