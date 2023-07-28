#include "main.h"

/**
 * getFlag - turns on flag if _printf finds
 * a flag modifier in format string
 * @s: character that holds the flag specifier
 * @f: pointer to the struct flag in which we turn the flags on
 *
 * Return: 1 if a flag has been turned on, 0 otherwise
 */
int getFlag(char s, flag_opter *f)
{
	int u = 0;

	switch (s)
	{
		case '+':
			f->plus = 1;
			u = 1;
			break;
		case ' ':
			f->space = 1;
			u = 1;
			break;
		case '#':
			f->hash = 1;
			u = 1;
			break;
	}

	return (u);
}
