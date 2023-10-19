#include "monty.h"
/**
 * _div - function that dvide the top two elements
 * of stack
 * @head: head of stack
 * @line_number: line number
 *
 * Return : nothing
*/
void _div(stack_t **head, unsigned int line_number)
{
	stack_t *p;
	int length = 0, tmp;

	p = *head;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't div, stack too short\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	tmp = p->next->n / p->n;
	p->next->n = tmp;
	*head = p->next;
	free(p);
}

/**
 * _mod- compute the rest of the division of the second
 * top elemnt of the stack by the top elemnt
 * @head: head of stack
 * @line_number: line number
 *
 * Return: nothing
*/
void _mod(stack_t **head, unsigned int line_number)
{
	stack_t *p;
	int length = 0, tmp;

	p = *head;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mod, stcak too short\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	if (p->n == 0)
	{
		fprintf(stderr, "L%d: division by zero\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	tmp = p->next->n % p->n;
	p->next->n = tmp;
	*head = p->next;
	free(p);
}

/**
 * _mul - multiplies the top two elements of stack
 * @head: head of stack
 * @line_number: line number
 *
 * Return: nothing
*/
void _mul(stack_t **head, unsigned int line_number)
{
	stack_t *p;
	int length = 0, tmp;

	p = *head;
	while (p != NULL)
	{
		p = p->next;
		length++;
	}
	if (length < 2)
	{
		fprintf(stderr, "L%d: can't mul, stack too short\n", line_number);
		fclose(info.file);
		free(info.line_content);
		stack_free(*head);
		exit(EXIT_FAILURE);
	}
	p = *head;
	tmp = p->next->n * p->n;
	p->next->n = tmp;
	*head = p->next;
	free(p);
}
