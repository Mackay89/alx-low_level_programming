#include "lists.h"

/**
 * get_dnodeint_at_index - Returns the nth node of a dlistint_t linked list.
 * @head: the pointer to the head of the dlistint_t list
 * @index: The index of the node, starting from 0
 * Return: The nth node, or NULL if the node does not exit
 */
dlistint_t *get_dnodeint_at_index(dlistint_t *head, unsigned int index)
{
	unsigned int i;
	dlistint_t *temp = head;

	for (i = 0; temp != NULL && i < index; i++)
	{
		temp = temp->next;
	}

	return (temp);
}
