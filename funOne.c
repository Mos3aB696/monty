#include "monty.h"

/**
 * _push -add node to stack
 * @head: stack head
 * @line_number: line_number
 *
 * Return: nothing
 */
void _push(stack_t **head, unsigned int line_number)
{
	int num, i = 0, flag = 0;

	if (info.arg)
	{
		if (info.arg[0] == '-')
			i++;
		for (; info.arg[i] != '\0'; i++)
		{
			if (info.arg[i] > 57 || info.arg[i] < 48)
				flag = 1; }
		if (flag == 1)
		{
			fprintf(stderr, "L%d: usage: push integer\n", line_number);
			fclose(info.file);
			free(info.line_content);
			stack_free(*head);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		fprintf(stderr, "L%d: usage:push integer\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	num = atoi(info.arg);
	if (info.f_change == 0)
		addnode(head, num);
	else
		addqueue(head, num);
}

/**
 * _pall - function that print stack
 * @head: stach head
 * @line_number: not used
 *
 * Reaturn: nothing
 */
void _pall(stack_t **head, unsigned int line_number)
{
	stack_t *p;
	(void)line_number;

	p = head;
	if (p == NULL)
		return;
	while (p)
	{
		printf("%d\n", p->n);
		p = p->next;
	}
}

/**
 * _pint- prints the top
 * @head: stack head
 * @line_number: line_number
 *
 * Return: nothing
 */
void _pint(stack_t **head, unsigned int line_number)
{
	if (*head == NULL)
	{
		fprintf(stderr, "L%u: can't pint, stack empty\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}

	printf("%d\n", (*head)->n);
}
