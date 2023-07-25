#include "main.h"

/**
 * print_hoct - prints long decimal number in octal
 * @arguments: input number
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_hoct(va_list arguments, char *buf, unsigned int ibuf)
{
	short int int_enter, i, isnegative, count, first_digit;
	char *octal, *binary;

	int_enter = va_arg(arguments, int);
	isnegative = 0;
	if (int_enter == 0)
	{
		ibuf = buf_con(buf, '0', ibuf);
		return (1);
	}
	if (int_enter < 0)
	{
		int_enter = (int_enter * -1) - 1;
		isnegative = 1;
	}

	binary = malloc(sizeof(char) * (16 + 1));
	binary = bin_array(binary, int_enter, isnegative, 16);
	octal = malloc(sizeof(char) * (6 + 1));
	octal = short_oct(binary, octal);
	for (first_digit = i = count = 0; octal[i]; i++)
	{
		if (octal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = buf_con(buf, octal[i], ibuf);
			count++;
		}
	}
	free(binary);
	free(octal);
	return (count);
}
