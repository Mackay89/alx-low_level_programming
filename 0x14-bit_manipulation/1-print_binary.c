#include "main.h"

/**
 * print_binary - prints the binary equivalent of decimal number
 * @n: number to print in binary
 */
void print_binary(unsigned long int n)
{
	int i, current = 0;
	unsigned long int count;

	for (i = 63; i >= 0; i--)
	{
		count = n >> i;

		if (count & 1)
		{
			_putchar('1');
			count++;
		}
		else if (current)
			_putchar('0');
	}
	if (!current)
		_putchar('0');
}
