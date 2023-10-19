#include "monty.h"

/**
 * _execute - executes the opcode
 * @stack: stack
 * @line_number: line_number
 * @file: pointer to monty file
 * @line_content: line content
 *
 * Return: nothing
*/
int _execute(char *line_content, stack_t **stack, unsigned int line_number,
FILE *file)
{
	instruction_t mrmr[] = {{"push", _push}, {"pop", _pop},
													{"swap", _swap}, {"add", _add},
													{"nop", _nop}, {"queue", _queue},
													{"pint", _pint}, {NULL, NULL}};
	unsigned int i = 0;
	char *op;

	op = strtok(line_content, "\n\t");
	if (op && op[0] == '#')
		return (0);
	info.arg = strtok(NULL, "\n\t");
	while (mrmr[i].opcode && op)
	{
		if (strcmp(op, mrmr[i].opcode) == 0)
		{
			mrmr[i].f(stack, line_number);
			return (0);
		}
		i++;
	}
	if (op && mrmr[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op);
		fclose(file);
		free(line_content);
		stack_free(*stack);
		exit(EXIT_FAILURE);
	}
	return (1);
}
