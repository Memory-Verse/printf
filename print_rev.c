#include "main.h"

/**
 * rev - writes the str in reverse
 * @arguments: input string
 * @buf: buffer pointer
 * @ibuf: index for buffer pointer
 * Return: number of chars printed.
 */
int rev(va_list arguments, char *buf, unsigned int ibuf)
{
	char *str;
	unsigned int i;
	int j = 0;
	char nill[] = "(llun)";

	str = va_arg(arguments, char *);
	if (str == NULL)
	{
		for (i = 0; nill[i]; i++)
			ibuf = buf_con(buf, nill[i], ibuf);
		return (6);
	}
	for (i = 0; str[i]; i++)
		;
	j = i - 1;
	for (; j >= 0; j--)
	{
		ibuf = buf_con(buf, str[j], ibuf);
	}
	return (i);
}
