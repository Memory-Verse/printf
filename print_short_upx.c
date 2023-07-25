#include "main.h"

/**
 * print_hupx - prints a short decimal in hexadecimal
 * @arguments: The character to print
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed
 */
int print_hupx(va_list arguments, char *buf, unsigned int ibuf)
{
	short int int_enter, i, isnegative, count, first_digit;
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

	binary = malloc(sizeof(char) * (16 + 1));
	binary = bin_array(binary, int_enter, isnegative, 16);
	hexadecimal = malloc(sizeof(char) * (4 + 1));
	hexadecimal = hex_array(binary, hexadecimal, 1, 4);

	for (first_digit = i = count = 0; hexadecimal[i]; i++)
	{
		if (hexadecimal[i] != '0' && first_digit == 0)
			first_digit = 1;
		if (first_digit)
		{
			ibuf = buf_con(buf, hexadecimal[i], ibuf);
			count++;
		}
	}

	free(binary);
	free(hexadecimal);

	return (count);
}
