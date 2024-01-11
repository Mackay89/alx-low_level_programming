#include "lists.h"

/**
 * dlistint_len - Returns the number of elemrnts in a link dlistint_t list
 * @h: The pointer to the head of the list
 * Return: the number of elements
 */
size_t dlistint_len(const dlistint_t *h)
{
	size_t num_elements = 0;

	while (h)
	{
		h = h->next;
		num_elements = num_elements + 1;
	}
	return (num_elements);
}
