#include "monty.h"

/**
 * stack_free - free the double linked list
 * @head: head of stack
 *
 * Return: void
 */
void stack_free(stack_t *head)
{
	stack_t *temp;

	temp = head;
	while (head)
	{
		temp = head->next;
		free(head);
		head = temp;
	}
}

/**
 * _queue - prints the top
 * @head: stack head
 * @line_number: line_number
 *
 * Return: nothing
 */
void _queue(stack_t **head, unsigned int line_number)
{
	(void)head;
	(void)line_number;
	info.f_change = 1;
}

/**
 * addqueue - add node at the tail stack
 * @head: head of the stack
 * @num: newValue
 *
 * Return: nothing
 */
void addqueue(stack_t **head, int num)
{
	stack_t *new, *ptr;

	ptr = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
	}
	new->n = num;
	new->next = NULL;
	if (ptr)
	{
		while (ptr->next)
			ptr = ptr->next;
	}
	if (ptr == NULL)
	{
		*head = new;
		new->prev = NULL;
	}
	else
	{
		ptr->next = new;
		new->prev = ptr;
	}
}

/**
 * addnode - add node to the head stack
 * @head: head of atack
 * @num: newValue
 *
 * Return: nothing
 */
void addnode(stack_t **head, int num)
{
	stack_t *new, *ptr;

	ptr = *head;
	new = malloc(sizeof(stack_t));
	if (new == NULL)
	{
		printf("Error\n");
		exit(0);
	}

	if (ptr)
		ptr->prev = new;
	new->n = num;
	new->next = *head;
	new->prev = NULL;
	*head = new;
}
