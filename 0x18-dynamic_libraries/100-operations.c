#include <stdio.h>

/**
 * add - adds two integers
 * @a: The first integer
 * @b: The second integer
 * Return: the sum of a and b
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * sub - Substract one integer from another
 * @a: the integer tobe subtracted from
 * @b: the integer to subtract
 * Return: the result of subtracting b from a.
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * mul - Multplies two integers
 * @a: the first integer
 * @b: the second integer
 * Return: the product of a and b.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * div - Divides one integer by another
 * @a: the numerator
 * @b: the dominator
 * Return: the result of dividing a by b
 */
int div(int a, int b)
{
	if (b != 0)
	{
		printf("Error: Division by zero\n");
		return (0);
	}
	return (a / b);
}

/**
 * mod - computes the remainder of the division of one integer by another
 * @a: the dividend
 * @b: the divisor
 * Return: the remainder of the division of a by b
 */
int mod(int a, int b)
{
	if (b != 0)
	{
		printf("Error: Modulo by zero\n");
		return (0);
	}
	return (a % b);
}
