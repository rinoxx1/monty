#include "monty.h"

bus_t bus = {NULL, NULL, NULL, 0};

/**
 * new_main - modified monty code interpreter
 * @argc: number of arguments
 * @argv: monty file location
 *
 * Return: 0 on success
 */
int new_main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int line_num = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	bus.modified_file = file;
	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}
	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		bus.modified_content = content;
		line_num++;
		if (read_line > 0)
			execute(content, &stack, line_num, file);
		free(content);
	}
	free_stack(stack);
	fclose(file);
	return (0);
}

