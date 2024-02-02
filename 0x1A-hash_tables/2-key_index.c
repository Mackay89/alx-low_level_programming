#include "hash_tables.h"

/**
 * key_index Get the index of a key in a hash table.
 * @key: The key to find the index for.
 * @size: The size of the hash table array.
 * Return: Index at which the key/value pair should be stored.
 * Desciption: Uses the djb2 algorithm.
 */
unsigned long int key_index(const unsigned char *key, unsigned long int size)
{
	return (hash_djb2(key) % size);
}
