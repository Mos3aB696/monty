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
