#include "main.h"
/**
 * get_print_func - selects the correct function to perform the operation.
 * @s: argument indentifier
 * @index: index for argument indentifier
 * Return: pointer to a function.
 */
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int)
{
	print_b pr[] = {
		{"c", print_character}, {"s", print_string},
		{"i", print_int}, {"d", print_int},
		{"b", print_dec_bnr}, {"u", print_unt_int},
		{"o", print_dec_oct}, {"x", print_hex},
		{"X", print_dechex}, {"S", print_strv},
		{"p", print_address}, {"li", print_long_int},
		{"ld", print_long_int}, {"lu", print_lunt},
		{"lo", print_loct}, {"lx", print_lhex},
		{"lX", print_lupx}, {"hi", print_shint},
		{"hd", print_shint}, {"hu", print_shunt},
		{"ho", print_hoct}, {"hx", print_shhex},
		{"hX", print_hupx}, {"#o", print_noct},
		{"#x", print_hex}, {"#X", print_upper_hex},
		{"#i", print_int}, {"#d", print_int},
		{"#u", print_unt_int}, {"+i", print_int_sym},
		{"+d", print_int_sym}, {"+u", print_unt_int},
		{"+o", print_dec_oct}, {"+x", print_hex},
		{"+X", print_dechex}, {" i", print_sint},
		{" d", print_sint}, {" u", print_unt_int},
		{" o", print_dec_oct}, {" x", print_hex},
		{" X", print_dechex}, {"R", rot},
		{"r", rev}, {"%", print_prg},
		{"l", print_prg}, {"h", print_prg},
		{" +i", print_int_sym}, {" +d", print_int_sym},
		{"+ i", print_int_sym}, {"+ d", print_int_sym},
		{" %", print_prg}, {NULL, NULL},
	};
	int i = 0, j = 0, first_index;

	first_index = index;
	while (pr[i].type_arg)
	{
		if (s[index] == pr[i].type_arg[j])
		{
			if (pr[i].type_arg[j + 1] != '\0')
				index++, j++;
			else
				break;
		}
		else
		{
			j = 0;
			i++;
			index = first_index;
		}
	}
	return (pr[i].f);
}
