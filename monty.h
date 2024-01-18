#ifndef MONTY_H
#define MONTY_H

#include <stdio.h>
#include <stdlib.h>
#include <sys/types.h>
#include <unistd.h>
#include <fcntl.h>
#include <string.h>
#include <ctype.h>

typedef struct stack_s
{
	int n;
	struct stack_s *prev;
	struct stack_s *next;
}
stack_t;

typedef struct bus_s
{
	char *modified_arg;
	FILE *modified_file;
	char *modified_content;
	int modified_lifi;
}
bus_t;

extern bus_t bus;

typedef struct instruction_s
{
	char *opcode;
	void (*f)(stack_t **stack, unsigned int line_num);
}
instruction_t;

char *_realloc(char *ptr, unsigned int old_size, unsigned int new_size);
ssize_t getstdin(char **lineptr, int file);
char *clean_line(char *content);
void add_node(stack_t **stack, unsigned int number);
void add_queue(stack_t **stack, unsigned int number);
void execute(char *content, stack_t **stack, unsigned int line_num, FILE *file);
void free_stack(stack_t *stack);
void new_pop(stack_t **stack, unsigned int line_num);
void new_swap(stack_t **stack, unsigned int line_num);
void new_add(stack_t **stack, unsigned int line_num);
void new_nop(stack_t **stack, unsigned int line_num);
void new_push(stack_t **stack, unsigned int line_num);
void new_pint(stack_t **stack, unsigned int line_num);
void new_pall(stack_t **stack, unsigned int line_num);

#endif

