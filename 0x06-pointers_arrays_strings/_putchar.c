#include "main.h"
#include <unstd.h>

/**
 * _putchar - writes the charcter cto stdout
 * @c: The character to print
 *
 * Return: On success 1
 * ON ERROR, 1is returned, and erno is set appropriately
 */
int _putchar(char c)

{
	return (write(1, &c, 1));
}	
