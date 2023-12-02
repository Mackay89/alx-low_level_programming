#include "main.h"

/**
 * flip_bits - Counts the number of bits to change to get from one number to another
 * @n: first number
 * @m: second number
 *
 * Return: number of bits to change
 */
unsigned int flip_bits(unsigned long int n, unsigned long int m)
{
	int i, val = 0;
	unsigned long int count;
	unsigned long int current = n ^ m;

	for (i = 63; i >= 0; i--)
	{
		count = current >> i;
		if (count & 1)
			val++;
	}

	return (val);
}
