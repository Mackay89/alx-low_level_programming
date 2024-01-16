#include <unistd.h>
#include <stdlib.h>
#include <string.h>

/**
 * _putchar - Writes the character c to stdout
 * @c: The character to print
 * Return: On success 1
 * On error -1 is return, and errno is set appropriately
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * _islower - Checks if a character is lowercase
 * @c: The character to check
 * Return: 1 if c is lowercase, 0 otherwise
 */
int _islower(int c)
{
	return (c >= 'a' && c <= 'z');
}

/**
 * _abs - computes the absolute value of an integer
 * @n: the integer to compute the absolute value of
 * Return: the absolute value of n
 */
int _abs(int n)
{
	return (n < 0) ? -n : n;
}

/**
 * _isalpha - checks if a character is alphabetic
 * @c: the character to check
 * Return: 1 if c is alphabetic, 0 otherwise
 */
int _salpha(int c)
{
	return ((c >= 'a' && c <= 'z') || (c >= 'A' && c <= 'Z'));
}

/**
 * _isupper - checks if a character is uppercase
 * @c: the character to check
 * Return: 1 if c is uppercase, 0 otherwise
 */
int _isupper(int c)
{
	return (c >= 'A' && c <= 'Z');
}

/**
 * _isdigit - Checks if the character is a digit
 * @c: the character to check
 * Return: 1 if c is digit, 0 otherwise
 */
int _isdigit(int c)
{
	return (c >= '0' && c <= '9');
}

/**
 * _strlen - computes the length of string
 * @s: thee string to compute the length of
 * Return: the length of the string
 */
int _strlen(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	return count;
}

/**
 * _strcpy - Copies a string
 * @dest: The destination buffer
 * @src: The source string
 * Return: A pointer to the destination buffer
 */
char *_strcpy(char *dest, char *src)
{
	char *original_dest = dest;

	while ((*dest++ = *src++) != '\0');
	return original_dest;
}

/**
 * _atoi - Converts a string to an integer
 * @s: The string to convert
 * Return: The converted integer
 */
int _atoi(char *s)
{
	int result = 0;

	while (*s >= '0' && *s <= '9')
	{
		result = result * 10 + (*s - '0');
	       	s++;
	}
	return result;
}

/**
 * _strcat - Concatenates two strings
 * @dest: The destination buffer
 * @src: The source string
 * Return: A pointer to the destination buffer
 */
char *_strcat(char *dest, char *src)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}
	while ((*dest++ = *src++) != '\0');
        return original_dest;
}

/**
 * _strncat - Concatenates n characters of two strings
 * @dest: The destination buffer
 * @src: The source string
 * @n: The number of characters to concatenate
 * Return: A pointer to the destination buffer
 */
char *_strncat(char *dest, char *src, int n)
{
	char *original_dest = dest;

	while (*dest != '\0')
	{
		dest++;
	}

	while (n-- > 0 && (*dest++ = *src++) != '\0');
	*dest = '\0'; // Ensure null-termination
	return original_dest;
}

/**
 * _strncpy - Copies n characters of a string
 * @dest: The destination buffer
 * @src: The source string
 * @n: The number of characters to copy
 * Return: A pointer to the destination buffer
 */
char *_strncpy(char *dest, char *src, int n)
{
	char *original_dest = dest;

	while (n-- > 0 && (*dest++ = *src++) != '\0');

	while (n-- > 0)
	{
		*dest++ = '\0';
	}

	return original_dest;
}

/**
 * _strcmp - Compares two strings
 * @s1: The first string
 * @s2: The second string
 * Return: 0 if the strings are equal, a negative value if s1 is less than s2,
 * a positive value if s1 is greater than s2
 */
int _strcmp(char *s1, char *s2)
{
	while (*s1 && (*s1 == *s2))
	{
		s1++;
		s2++;
	}

	return *(unsigned char *)s1 - *(unsigned char *)s2;
}

/**
 * _memset - Fills the first n bytes of memory with a constant byte
 * @s: The memory area to fill
 * @b: The byte to fill with
 * @n: The number of bytes to fill
 * Return: A pointer to the filled memory area
 */
char *_memset(char *s, char b, unsigned int n)
{
	while (n-- > 0)
	{
		*s++ = b;
	}

	return s;
}

/**
 * _memcpy - Copies n bytes from source to destination
 * @dest: The destination buffer
 * @src: The source buffer
 * @n: The number of bytes to copy
 * Return: A pointer to the destination buffer
 */
char *_memcpy(char *dest, char *src, unsigned int n)
{
	char *original_dest = dest;

	while (n-- > 0)
	{
		*dest++ = *src++;
	}
	return original_dest;
}

/**
 * _strchr - Locates the first occurrence of a character in a string
 * @s: The string to search
 * @c: The character to find
 * Return: A pointer to the first occurrence of c in s, or NULL if not found
 */
char *_strchr(char *s, char c)
{
	while (*s != '\0' && *s != c)
	{
		s++;
	}
	return (*s == c) ? s : NULL;
}

/**
 * _strspn - Gets the length of a prefix substring consisting of only accepted characters
 * @s: The string to search
 * @accept: The characters to accept
 * Return: The length of the prefix
 */
unsigned int _strspn(char *s, char *accept)
{
	unsigned int count = 0;

	while (*s != '\0' && strchr(accept, *s) != NULL)
	{
		count++;
		s++;
	}

	return count;
}

/**
 * _strpbrk - Searches a string for any set of bytes
 * @s: The string to search
 * @accept: The set of bytes to search for
 * Return: A pointer to the first occurrence in s of any byte in accept, or NULL if no such byte is found
 */
char *_strpbrk(char *s, char *accept)
{
	while (*s != '\0')
	{
		if (strchr(accept, *s) != NULL)
		{
			return s;
		}
		s++;
	}

	return NULL;
}

/**
 * _strstr - Locates a substring in another string
 * @haystack: The string to search
 * @needle: The substring to locate
 * Return: A pointer to the beginning of the located substring, or NULL if the
 */
char *_strstr(char *haystack, char *needle)
{
	size_t needle_len = strlen(needle);

	while (*haystack != '\0')
	{
		if (strncmp(haystack, needle, needle_len) == 0)
		{
			return haystack;
		}
	}

        haystack++;
	return NULL;
}

