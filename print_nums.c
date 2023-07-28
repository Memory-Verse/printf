#include "main.h"

/**
 * printInt - prints an integer
 * @x: va_list of arguments from _printf
 * @y: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int printInt(va_list x, flag_opter *y)
{
	int k = va_arg(x, int);
	int les = countDigit(k);

	if (y->space == 1 && y->plus == 0 && k >= 0)
		les += _putchar(' ');
	if (y->plus == 1 && k >= 0)
		les += _putchar('+');
	if (k <= 0)
		les++;
	printNumber(k);
	return (les);
}

/**
 * printUnsigned - prints an unsigned integer
 * @x: va_list of arguments from _printf
 * @y: pointer to the struct flags determining
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int printUnsigned(va_list x, flag_opter *y)
{
	unsigned int k = va_arg(x, unsigned int);
	char *str = convert(k, 10, 0);

	(void)y;
	return (_puts(str));
}

/**
 * printNumber - helper function that loops through
 * an integer and prints all its digits
 * @i: integer to be printed
 */
void printNumber(int i)
{
	unsigned int i1;

	if (i < 0)
	{
		_putchar('-');
		i1 = -i;
	}
	else
		i1 = i;

	if (i1 / 10)
		printNumber(i1 / 10);
	_putchar((i1 % 10) + '0');
}

/**
 * countDigit - returns the number of digits in an integer
 * for _printf
 * @k: integer to evaluate
 * Return: number of digits
 */
int countDigit(int k)
{
	unsigned int d = 0;
	unsigned int u;

	if (k < 0)
		u = k * -1;
	else
		u = k;
	while (u != 0)
	{
		u /= 10;
		d++;
	}
	return (d);
}
