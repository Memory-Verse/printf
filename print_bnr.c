#include "main.h"

/**
 * print_dec_bnr - prints decimal in binary
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int print_dec_bnr(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_enter, count, i, first_one, isnegative;
	char *binary;

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
	binary = malloc(sizeof(char) * (32 + 1));
	binary = bin_array(binary, int_enter, isnegative, 32);
	first_one = 0;
	for (count = i = 0; binary[i]; i++)
	{
		if (first_one == 0 && binary[i] == '1')
			first_one = 1;
		if (first_one == 1)
		{
			ibuf = buf_con(buf, binary[i], ibuf);
			count++;
		}
	}
	free(binary);
	return (count);
}
