#include "hash_tables.h"
#include <stdlib.h>
#include <string.h>
#include <stdio.h>

/**
 * shash_table_create - Creates a sorted hash table.
 * @size: The size of new sorted hash table.
 *
 * Return: If an error occurs - NULL.
 *         Otherwise - a pointer to the new sorted hash table.
 */
shash_table_t *shash_table_create(unsigned long int size)
{
	shash_table_t *ht;
	unsigned long int i;

	ht = malloc(sizeof(shash_table_t));
	if (ht == NULL)
		return (NULL);

	ht->size = size;
	ht->array = malloc(sizeof(shash_node_t *) * size);
	if (ht->array == NULL)
		return (NULL);
	for (i = 0; i < size; i++)
		ht->array[i] = NULL;
	ht->shead = NULL;
	ht->stail = NULL;

	return (ht);
}

/**
 * shash_table_set - functtion that add an element to a sorted hash table.
 * @ht: Pointer to the sorted hash table.
 * @key: The key to add te element
 * @value: The value to add the element.
 * Return: Upon failure - 0, Otherwise - 1.
 */
int shash_table_set(shash_table_t *ht, const char *key, const char *value)
{
	shash_node_t *new_node, *tmp, *prev;
	char *value_copy, *key_copy;


	if (!ht || !key || !*key || !value)
		return (0);

	value_copy = strdup(value);
	if (!value_copy)
		return (0);


	tmp = ht->shead;
	prev = NULL;


	while (tmp && strcmp(key, tmp->key) > 0)
	{
		prev = tmp;
		tmp = tmp->snext;
	}

	new_node = calloc(1, sizeof(shash_node_t));
	if (!new_node)
	{
		free(value_copy);
		return (0);
	}

	key_copy = strdup(key);
	if (!key_copy)
	{
		free(value_copy);
		free(new_node);
		return (0);
	}

	new_node->key = key_copy;
	new_node->value = value_copy;


	if (prev == NULL)
	{
		new_node->snext = ht->shead;
		ht->shead = new_node;
	}
	else
	{
		new_node->snext = prev->snext;
		prev->snext = new_node;
	}


	return (1);
}

/**
 * shash_table_get - function to retrieve value with associeted with key
 * @ht: A pointer to the sorted hash table.
 * @key: The key to get the value of.
 *
 * Return: value or NULL if key does not exit.
 */
char *shash_table_get(const shash_table_t *ht, const char *key)
{
	shash_node_t *node;
	unsigned long int index = 0;

	if (!ht || !key || !*key)
		return (NULL);

	index = key_index((const unsigned char *)key, ht->size);
	node = ht->array[index];
	while (node)
	{
		if (!strcmp(key, node->key))
			return (node->value);
		node = node->next;
	}
	return (NULL);
}

/**
 * shash_table_print - Prints a sorted hash table in order.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_print(const shash_table_t *ht)
{
	shash_node_t *node;
	int flag = 0;

	if (!ht)
		return;
	node = ht->shead;
	printf("{");
	while (node)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
		node = node->snext;
	}
	printf("}\n");
}

/**
 * shash_table_print_rev - Prints a sorted hash table in reverse order.
 * @ht: A pointer to the sorted hash table to print.
 */
void shash_table_print_rev(const shash_table_t *ht)
{
	shash_node_t *node;
	int flag = 0;

	if (!ht)
		return;

	node = ht->stail;
	printf("{");
	while (node != NULL)
	{
		if (flag)
			printf(", ");
		printf("'%s': '%s'", node->key, node->value);
		flag = 1;
		node = node->sprev;
	}
	printf("}\n");
}

/**
 * shash_table_delete - Deletes a sorted hash table.
 * @ht: A pointer to the sorted hash table.
 */
void shash_table_delete(shash_table_t *ht)
{
	shash_node_t *node, *tmp;
	unsigned long int i = 0;

	if (!ht)
		return;

	for (i = 0; i < ht->size; i++)
	{
		node = ht->array[i];
		while (node)
		{
			tmp = node;
			node = node->next;
			if (tmp->next)
				free(tmp->key);
			if (tmp->value)
				free(tmp->value);
			free(tmp);
		}
	}
	free(ht->array);
	free(ht);
}
