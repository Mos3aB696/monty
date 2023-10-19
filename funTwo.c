#include "monty.h"

/**
 * _pop - removes the top element of the stack
 * @head: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _pop(stack_t **head, unsigned int line_number)
{
	stack_t *temp;

	if (*head == NULL)
	{
		fprintf(stderr, "L<line_number>: can't pop an empty stack\n", line_number);
		fclose(info.file);
		free(info.content);
		stack_free(*head);
		exit(EXIT_FAILURE)
	}
	temp = *head;
	*head = temp->next;
	free(temp);
}

/**
 * _swap - swaps the top two elements of the stack
 * @head: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _swap(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, tmp;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L<line_number>: can't swap, stack too short\n",
						line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	tmp = temp->n;
	temp->n = temp->next->n;
	temp->next->n = tmp;
}

/**
 * _add - adds the top two elements of the stack
 * @head: head of stack
 * @line_number: line number
 *
 * Return: void
 */

void _add(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int len = 0, tmp;

	temp = *head;
	while (temp)
	{
		temp = temp->next;
		len++;
	}
	if (len < 2)
	{
		fprintf(stderr, "L<line_number>: can't add, stack too short\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	tmp = temp->n + temp->next->n;
	temp->next->n = tmp;
	*head = temp->next;
	free(temp);
}
/**
 * _nop - doesn't do anything
 * @head: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _nop(stack_t **head, unsigned int line_number)
{
	(void)line_number;
	(void)head;
}
