#include "main.h"

/**binary_to_uint - Binary can be converted through unsigned int
 * #b: The string containing binary number
 * Return: The converted number
 */
unsigned int binary_to_uint(const char *b)
{
	int i;
	unsigned int current = 0;

	if (!b)
		return (0);

	for (i = 0; b[i]; i++)
	{
		if (b[i] < '0' || b[i] > '1')
			return (0);
		current = 2 * current + (b[i] - '0');
	}

	return (current);
}
