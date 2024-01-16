#include <stdio.h>

/**
 * _add - adds two numbers and returns the results
 */
int add(int a, int b)
{
	return (a + b);
}

/**
 * _sub - Substract the second number from the first and returns the result.
 */
int sub(int a, int b)
{
	return (a - b);
}

/**
 * _mul - Multplies two numbers and return the result.
 */
int mul(int a, int b)
{
	return (a * b);
}

/**
 * _div -Divides the first number by the second and returns the result.
 * @n: ensure the second number (denominator) is not zero to void division
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
 * _mod - computes the remainder when the first number is divided by the second
 * Note: ensure that the second number (modulus) is not zero to avoid division
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
