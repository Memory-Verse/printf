#include "main.h"

/**
 * _printf - formatted output conversion and print data.
 * @format: input string.
 *
 * Return: number of chars printed.
 */
int _printf(const char *format, ...)
{
	unsigned int k = 0, len = 0, ibuf = 0;
	va_list arguments;
	int (*function)(va_list, char *, unsigned int);
	char *buffer;

	va_start(arguments, format), buffer = malloc(sizeof(char) * 1024);
	if (!format || !buffer || (format[k] == '%' && !format[k + 1]))
		return (-1);
	if (!format[k])
		return (0);
	for (k = 0; format && format[k]; k++)
	{
		if (format[k] == '%')
		{
			if (format[k + 1] == '\0')
			{	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
				return (-1);
			}
			else
			{	function = get_print_func(format, k + 1);
				if (function == NULL)
				{
					if (format[k + 1] == ' ' && !format[k + 2])
						return (-1);
					buf_con(buffer, format[k], ibuf), len++, k--;
				}
				else
				{
					len += function(arguments, buffer, ibuf);
					k += ev_print_func(format, k + 1);
				}
			} k++;
		}
		else
			buf_con(buffer, format[k], ibuf), len++;
		for (ibuf = len; ibuf > 1024; ibuf -= 1024)
			;
	}
	print_buf(buffer, ibuf), free(buffer), va_end(arguments);
	return (len);
}