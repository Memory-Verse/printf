#include "main.h"

/**
 * hex_array - writes the character c to stdout
 *
 * @bnr: array where is stored the binary.
 * @hex: array where is stored the hexadecimal.
 * @isupp: integer that determines if the hexadecimal array is
 * in uppercase or lowercase letter.
 * @limit: size of hex
 * Return: binary array.
 */
char *hex_array(char *bnr, char *hex, int isupp, int limit)
{
	int pp, k, l, toalpha;
	hex[limit] = '\0';
	if (isupp)
		toalpha = 55;
	else
		toalpha = 87;
	for (k = (limit * 4) - 1; k >= 0; k--)
	{
		for (pp = 0, l = 1; l <= 8; l *= 2, k--)
			pp = ((bnr[k] - '0') * l) + pp;
		k++;
		if (pp < 10)
			hex[k / 4] = pp + 48;
		else
			hex[k / 4] = pp + toalpha;
	}
	return (hex);
}
