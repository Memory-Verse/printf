#include "main.h"
#include <stdio.h>
/**
 * print_address - prints the address of an input variable
 * @arguments: input address.
 * @buf: buffer pointer.
 * @ibuf: index for buffer pointer
 *
 * Return: number of chars printed.
 */
int print_address(va_list arguments, char *buf, unsigned int ibuf)
{
	void *add;
	long int int_enter;
	int k, count, first_digit, isnegative;
	char *hexadecimal, *binary;
	char nill[] = "(nil)";

	add = (va_arg(arguments, void *));
	if (add == NULL)
	{
		for (k = 0; nill[k]; k++)
			ibuf = buf_con(buf, nill[k], ibuf);
		return (5);
	}
	int_enter = (intptr_t)add;
	isnegative = 0;
	if (int_enter < 0)
	{
		int_enter = (int_enter * -1) - 1;
		isnegative = 1;
	}
	binary = malloc(sizeof(char) * (64 + 1));
	binary = bin_array(binary, int_enter, isnegative, 64);
	hexadecimal = malloc(sizeof(char) * (16 + 1));
	hexadecimal = hex_array(binary, hexadecimal, 0, 16);
	ibuf = buf_con(buf, '0', ibuf);
	ibuf = buf_con(buf, 'x', ibuf);
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