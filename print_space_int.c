#include "main.h"

/**
 * print_sint - prints int begining with space
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_sint(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_enter;
	unsigned int int_in, int_temp, i, div;

	int_enter = va_arg(arguments, int);
	if (int_enter < 0)
	{
		int_in = int_enter * -1;
		ibuf = buf_con(buf, '-', ibuf);
	}
	else
	{
		int_in = int_enter;
		ibuf = buf_con(buf, ' ', ibuf);
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
	return (i + 1);
}
