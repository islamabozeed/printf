#include "main.h"

/**
 * is_printable - Calculates if a char is printable
 * @c: Char to be Calculated
 *
 * Return: 1 if c is printable, else 0
 */
int is_printable(char c)
{
	if (c >= 32 && c < 127)
		return (1);
	return (0);
}

/**
 * append_hexa_code - Append ascci in hexadecimal code's buffer
 * @buffer: Array's chars
 * @i: Index at which to start appending
 * @ascii_code: ASSCI CODE
 * Return: Always 3
 */
int append_hexa_code(char ascii_code, char buffer[], int i)
{
	char map_to[] = "0123456789ABCDEF";

	if (ascii_code < 0)
		ascii_code *= -1;

	buffer[i++] = '\\';
	buffer[i++] = 'x';

	buffer[i++] = map_to[ascii_code / 16];
	buffer[i] = map_to[ascii_code % 16];

	return (3);
}

/**
 * is_digit - Verifies if a char is a digit.
 * @c: Char to be calculated.
 * Return: 1 if c is a digit, else 0
 */
int is_digit(char c)
{
	if (c >= '0' && c <= '9')
		return (1);

	return (0);
}

/**
 * convert_size_number - Cast number to the specified size
 * @num: Number's casted.
 * @size: Number indicating the kind to be casted.
 * Return: Casted value of num.
 */
long int convert_size_number(long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((short)num);

	return ((int)num);
}

/**
 * convert_size_unsgnd - Cast number to the specified size
 * @num: Number's casted.
 * @size: Number indicating the kind to be casted
 * Return: Casted value of num
 */
long int convert_size_unsgnd(unsigned long int num, int size)
{
	if (size == LONG_SIZE)
		return (num);
	else if (size == SHORT_SIZE)
		return ((unsigned short)num);

	return ((unsigned int)num);
}
