#include "lists.h"

/**
 * add_dnodeint_end - Adds a new node at the end of a dlistint_t list
 * @head: pointer to the head of dlistint_t list
 * @n: the integer for the new node to store
 * Return: the address of the new node or NULL if it failed
 */
dlistint_t *add_dnodeint_end(dlistint_t **head, const int n)
{
	dlistint_t *node, *final;

	node = malloc(sizeof(dlistint_t));
	if (node == NULL)
		return (NULL);

	node->n = n;
	node->next = NULL;

	if (*head == NULL)
	{
		node->prev = NULL;
		*head = node;
		return (node);
	}

	final = *head;
	while (final->next != NULL)
		final = final->next;
	final->next = node;
	node->prev = final;

	return (node);
}
