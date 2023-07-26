#ifndef _MAIN_H_
#define _MAIN_H_

#include <stdarg.h>
#include <unistd.h>
#include <stdlib.h>
/**
 * struct print - struct for printer functions
 * @type_arg: identifier
 * @f: pointer to a printer functions
 *
 * Description: struct that stores pointers to a
 * printer functions.
 */
typedef struct print

{
	char *type_arg;
	int (*f)(va_list, char *, unsigned int);
} print_b;

int _printf(const char *format, ...);
int print_character(va_list arguments, char *buf, unsigned int ibuf);
int print_string(va_list arguments, char *buf, unsigned int ibuf);
int print_int(va_list arguments, char *buf, unsigned int ibuf);
int print_dec_bnr(va_list arguments, char *buf, unsigned int ibuf);
int print_unt_int(va_list arguments, char *buf, unsigned int ibuf);
int print_dec_oct(va_list arguments, char *buf, unsigned int ibuf);
int print_hexdec(va_list arguments, char *buf, unsigned int ibuf);
int print_dechex(va_list arguments, char *buf, unsigned int ibuf);
int print_lupx(va_list arguments, char *buf, unsigned int ibuf);
int print_shint(va_list arguments, char *buf, unsigned int ibuf);
int rev(va_list arguments, char *buf, unsigned int ibuf);
int print_shunt(va_list arguments, char *buf, unsigned int ibuf);
int print_hoct(va_list arguments, char *buf, unsigned int ibuf);
int print_shhex(va_list arguments, char *buf, unsigned int ibuf);
int print_hupx(va_list arguments, char *buf, unsigned int ibuf);
int print_int_sym(va_list arguments, char *buf, unsigned int ibuf);
int print_noct(va_list arguments, char *buf, unsigned int ibuf);
int print_strv(va_list arguments, char *buf, unsigned int ibuf);
int print_address(va_list arguments, char *buf, unsigned int ibuf);
int rot(va_list arguments, char *buf, unsigned int ibuf);
int print_long_int(va_list arguments, char *buf, unsigned int ibuf);
int print_lunt(va_list arguments, char *buf, unsigned int ibuf);
int print_loct(va_list arguments, char *buf, unsigned int ibuf);
int print_prg(va_list __attribute__((unused)), char *, unsigned int);
int print_lhex(va_list arguments, char *buf, unsigned int ibuf);
int print_hex(va_list arguments, char *buf, unsigned int ibuf);
int print_upper_hex(va_list arguments, char *buf, unsigned int ibuf);
int print_sint(va_list arguments, char *buf, unsigned int ibuf);
int (*get_print_func(const char *s, int index))(va_list, char *, unsigned int);
int ev_print_func(const char *s, int index);
unsigned int buf_con(char *buf, char c, unsigned int ibuf);
int print_buf(char *buf, unsigned int nbuf);
char *short_oct(char *bnr, char *oct);
char *bin_array(char *binary, long int int_in, int isneg, int limit);
char *oct_array(char *bnr, char *oct);
char *long_oct(char *bnr, char *oct);
char *hex_array(char *bnr, char *hex, int isupp, int limit);

#endif
