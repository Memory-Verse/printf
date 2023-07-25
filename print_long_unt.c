#include "main.h"
/**
 * print_lunt - prints a long unsigned integer
 * @arguments: number to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_lunt(va_list arguments, char *buf, unsigned int ibuf)
{
	unsigned long int int_long, int_temp, i, div;

	int_long = va_arg(arguments, unsigned long int);
	int_temp = int_long;
	div = 1;
	while (int_temp > 9)
	{
		div *= 10;
		int_temp /= 10;
	}
	for (i = 0; div > 0; div /= 10, i++)
	{
		ibuf = buf_con(buf, ((int_long / div) % 10) + '0', ibuf);
	}
	return (i);
}
