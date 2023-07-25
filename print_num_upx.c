#include "main.h"

/**
 * print_upper_hex - prints number in uppercase hex
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_upper_hex(va_list arguments, char *buf, unsigned int ibuf)
{
	int int_enter, k, isnegative, count, first_digit;
	char *hexadecimal, *binary;

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
	ibuf = buf_con(buf, '0', ibuf);
	ibuf = buf_con(buf, 'X', ibuf);
	binary = malloc(sizeof(char) * (32 + 1));
	binary = bin_array(binary, int_enter, isnegative, 32);
	hexadecimal = malloc(sizeof(char) * (8 + 1));
	hexadecimal = hex_array(binary, hexadecimal, 1, 8);
	for (first_digit = k = count = 0; hexadecimal[k]; k++)
	{
		if (hexadecimal[k] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = buf_con(buf, hexadecimal[k], ibuf);
			count++;
		}
	}
	free(binary);
	free(hexadecimal);
	return (count + 2);
}
