#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stdarg.h>

/**
 * struct flag - struct containing flag to "turn on"
 * when a flag specifier is passed to _printf()
 * @plus: flag for the '+' character
 * @space: flag for the ' ' character
 * @hash: flag for the '#' character
 */
typedef struct flag
{
	int plus;
	int space;
	int hash;
} flag_opter;

typedef struct printOpter
{
	char c;
	int (*f)(va_list ap, flag_opter *f);
} po;

int printOctal(va_list l, flag_opter *f);
char *convert(unsigned long int num, int base, int lowercase);
int _printf(const char *format, ...);
int (*getPrint(char s))(va_list, flag_opter *);
int getFlag(char s, flag_opter *f);
int printString(va_list l, flag_opter *f);
int printChar(va_list l, flag_opter *f);
int _putchar(char c);
int _puts(char *str);
int printRot13(va_list l, flag_opter *f);
int printRev(va_list l, flag_opter *f);
int printBigS(va_list l, flag_opter *f);
int printAddress(va_list l, flag_opter *f);
int printPercent(va_list l, flag_opter *f);
int printInt(va_list l, flag_opter *f);
void printNumber(int n);
int printUnsigned(va_list l, flag_opter *f);
int countDigit(int i);
int printHex(va_list l, flag_opter *f);
int printHexBig(va_list l, flag_opter *f);
int printBinary(va_list l, flag_opter *f);

#endif
