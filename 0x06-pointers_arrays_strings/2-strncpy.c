#include "main.h"


/**
 * _strncyp - Copies at most an inputted number
 * of bytes from string src into dest.
 * @dest: The buffer storing the string copy.
 * @src: The source string.
 * @n The maxima number of bytes to copied from src.
 * Return: dest
 */

char *_strncyp(char *dest, char *src, int n)
{
	int index = 0, src_len = 0;

	while (src[index++])
	src_len++;
	
	for (index = 0; src[index] && index < n; index++)
	dest[index] = src[index];

	for (index = src_len; index < n; index++)
	dest[index] = '\0';

	return (dest);

}	
