#define _GNU_SOURCE
#include "monty.h"

#include <stdio.h>
info_t info = {NULL, NULL, NULL, 0};
/**
 * main - code interpreter
 * @argc: number of args
 * @argv: file location
 *
 * Return: 0
 */
int main(int argc, char *argv[])
{
	char *content;
	FILE *file;
	size_t size = 0;
	ssize_t read_line = 1;
	stack_t *stack = NULL;
	unsigned int counter = 0;

	if (argc != 2)
	{
		fprintf(stderr, "USAGE: monty file\n");
		exit(EXIT_FAILURE);
	}
	file = fopen(argv[1], "r");
	info.file = file;

	if (!file)
	{
		fprintf(stderr, "Error: Can't open file %s\n", argv[1]);
		exit(EXIT_FAILURE);
	}

	while (read_line > 0)
	{
		content = NULL;
		read_line = getline(&content, &size, file);
		info.line_content = content;
		counter++;
		if (read_line > 0)
			_execute(content, &stack, counter, file);
		free(content);
	}
	stack_free(stack);
	fclose(file);
	return (0);
}
