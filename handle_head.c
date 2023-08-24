#include "monty.h"

/**
 * handle_dlist_head - Handle the head of a doubly linked list
 * @head: Address of the head of the linked list
 *
 * Return: Nothing.
 */
void handle_dlist_head(stack_t *head)
{
	stack_t *current = head;
	stack_t *next;

	while (current != NULL)
	{
		next = current->next;
		free(current);
		current = next;
	}
}
