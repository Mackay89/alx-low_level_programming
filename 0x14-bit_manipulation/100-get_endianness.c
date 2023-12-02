#include "main.h"

/**
 * get_endianness - check the machine if is a little or big indian
 * Return: 0 for big endian, 1 for little indian
 */
int get_endianness(void)
{
	unsigned int i = 1;
	char *c = (char *) &i;

	return (*c);
}
