#include "lists.h"

/**
 * free_dlistint - Frees a dlistint_ list
 * @head: the pointer to the head of the dlistint_t list
 */
void free_dlistint(dlistint_t *head)
{
	dlistint_t *new;

	while (head != NULL)
	{
		new = head->next;
		free(new);
		head = new;
	}
}
