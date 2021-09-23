#include "holberton.h"


/**
 * error - Prints "error" and exits with code 98
 * Return: Nothing
 */
void error(void)
{
	int a;
	char err[] = "Error\n";

	for (a = 0; a <= 5; a++)
		_putchar(err[a]);
	exit(98);
}

/**
 * main - check the code for Holberton School students.
 *
 * Return: Always 0.
 */
int main(void)
{
	error();
	return (0);
}
