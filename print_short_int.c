#include "main.h"

/**
 * print_shint - prints a short integer
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_shint(va_list arguments, char *buf, unsigned int ibuf)
{
	short int int_enter;
	unsigned short int int_in, int_temp, i, div, isneg;

	int_enter = va_arg(arguments, int);
	isneg = 0;
	if (int_enter < 0)
	{
		int_in = int_enter * -1;
		ibuf = buf_con(buf, '-', ibuf);
		isneg = 1;
	}
	else
	{
		int_in = int_enter;
	}
	int_temp = int_in;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = buf_con(buf, ((int_in / div) % 10) + '0', ibuf);
	}
	return (i + isneg);
}
