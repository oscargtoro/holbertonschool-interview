#include "palindrome.h"
#include <stdio.h>

/**
 * is_palindrome - checks if an unsigned long int is a palindrome.
 *
 * @n: unsigned int to check
 * Return: 1 if n is a palindrome, otherwise 0
 */
int is_palindrome(unsigned long n)
{
	unsigned long m = 0, modifiedn = n, remainder;

	while (modifiedn != 0)
	{
		remainder = modifiedn % 10;
		m = m * 10 + remainder;
		modifiedn = modifiedn / 10;
	}

	if (m == n)
		return (1);
	else
		return (0);
}
