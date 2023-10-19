#include "monty.h"

/**
 * _execute - executes the opcode
 * @content: line content
 * @head: head of stack
 * @line_number: line number
 * @file: monty file

 * Return: 1
 */

int _execute(char *content, stack_t **head, unsigned int line_number,
		FILE *file)
{
	instruction_t fun[] = {
			{"push", _push}, {"pall", _pall}, {"pint", _pint},
			{"pop", _pop}, {"swap", _swap}, {"add", _add},
			{"nop", _nop}, {"sub", _sub}, {"div", _div}, {"mul", _mul},
			{"mod", _mod}, {"pchar", _pchar}, {"pstr", _pstr},
			{"rotl", _rotl}, {"rotr", _rotr}, {"queue", _queue},
			{"stack", _stack}, {NULL, NULL}
			};
	unsigned int i = 0;
	char *op_code;

	op_code = strtok(content, " \n\t");
	if (op_code && op_code[0] == '#')
		return (0);
	info.arg = strtok(NULL, " \n\t");
	while (fun[i].opcode && op_code)
	{
		if (strcmp(op_code, fun[i].opcode) == 0)
		{
			fun[i].f(head, line_number);
			;
			return (0);
		}
		i++;
	}
	if (op_code && fun[i].opcode == NULL)
	{
		fprintf(stderr, "L%d: unknown instruction %s\n", line_number, op_code);
		fclose(file);
		free(content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	return (1);
}
