#include "monty.h"

/**
 * _pchar - prints the char
 * @head: head of stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _pchar(stack_t **head, unsigned int line_number)
{
	stack_t *p;

	p = *head;
	if (p == NULL)
	{
		fprintf(stderr, "L%d: can't pchar, stack empty", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	if (p->n > 127 || p->n < 0)
	{
		fprintf(stderr, "L%d: can't pchar, value out of range", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	printf("%c\n", p->n);
}

/**
 * _pstr - prints the string
 * @head: head of stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _pstr(stack_t **head, unsigned int line_number)
{
	stack_t *p;
	(void)line_number;

	p = *head;
	while (p != NULL)
	{
		if (p->n > 127 || p->n <= 0)
		{
			break;
		}
		printf("%c", p->n);
		p = p->next;
	}
	printf("\n");
}

/**
 * _rotl - rotates the stack to the top
 * @head: head of stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _rotl(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *p, *tmp;

	p = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	tmp = (*head)->next;
	tmp->prev = NULL;
	while (p->next != NULL)
	{
		p = p->next;
	}
	p->next = *head;
	(*head)->next = NULL;
	(*head)->prev = p;
	(*head) = tmp;
}

/**
 * _rotr - rotate the stack to the bottom
 * @head: head of stack
 * @line_number: line number
 *
 * Return: nothing
 */
void _rotr(stack_t **head, __attribute__((unused)) unsigned int line_number)
{
	stack_t *p;

	p = *head;
	if (*head == NULL || (*head)->next == NULL)
	{
		return;
	}
	while (p->next)
	{
		p = p->next;
	}
	p->next = *head;
	p->prev->next = NULL;
	p->prev = NULL;
	(*head)->prev = p;
	(*head) = p;
}

/**
 * _sub - subtracts the top element of the
 *  stack from the second top element of the stack
 * @head: head of stack
 * @line_number: line number
 *
 * Return: void
 */
void _sub(stack_t **head, unsigned int line_number)
{
	stack_t *temp;
	int result, nodes;

	temp = *head;
	for (nodes = 0; temp != NULL; nodes++)
		temp = temp->next;
	if (nodes < 2)
	{
		fprintf(stderr, "L%d: can't sub, stack too short\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	temp = *head;
	result = temp->next->n - temp->n;
	temp->next->n = result;
	*head = temp->next;
	free(temp);
}
