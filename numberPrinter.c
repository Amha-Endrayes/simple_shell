#include "shell.h"
/**
 * numberPrint -Print Unsigned Int Putchar
 * @n: Unisigned Integer
 * Return: Void
 */
void numberPrint(unsigned int n)
{
	unsigned int x = n;

	if ((x / 10) > 0)
		numberPrint(x / 10);

	_putchar(x % 10 + '0');
}
/**
 * intigerPrint -Print Number Putchar
 * @n:Integer
 * Return: void
 */
void intigerPrint(int n)
{
	unsigned int x = n;

	if (n < 0)
	{
		_putchar('-');
		x = -x;
	}
	if ((x / 10) > 0)
		numberPrint(x / 10);

	_putchar(x % 10 + '0');
}
