#include "main.h"
#include <stdio.h>
#include <limits.h>

/**formatted output string
 */
int _printf(const char *format, ...)
{
	int (*pfunc)(va_list, flag_opter *);
	const char *p;
	va_list arguments;
	flag_opter flag = {0, 0, 0};

	register int count = 0;

	va_start(arguments, format);
	if (!format || (format[0] == '%' && !format[1]))
		return (-1);
	if (format[0] == '%' && format[1] == ' ' && !format[2])
		return (-1);
	for (p = format; *p; p++)
	{
		if (*p == '%')
		{
			p++;
			if (*p == '%')
			{
				count += _putchar('%');
				continue;
			}
			while (getFlag(*p, &flag))
				p++;
			pfunc = getPrint(*p);
			count += (pfunc)
				? pfunc(arguments, &flag)
				: _printf("%%%c", *p);
		} else
			count += _putchar(*p);
	}
	_putchar(-1);
	va_end(arguments);
	return (count);

}
