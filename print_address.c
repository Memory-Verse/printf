#include "main.h"

/**
 * printAddress - prints address of input in hexa format
 * @x: va_list arguments from _printf
 * @y: pointer to the struct flags that determines
 * if a flag is passed to _printf
 * Return: number of char printed
 */
int printAddress(va_list x, flag_opter *y)
{
	char *str;
	unsigned long int p = va_arg(x, unsigned long int);

	register int count = 0;

	(void)y;

	if (!p)
		return (_puts("(nil)"));
	str = convert(p, 16, 1);
	count += _puts("0x");
	count += _puts(str);
	return (count);
}
