#include "main.h"

/**
 * prec - get the precision
 * @format: arg
 * @n: pointer to int
 * @list: arg list
 *
 * Return: Always 0
 */
int prec(const char *format, int *n, va_list list)
{
	int c_i = *n + 1;
	int prec = -1;

	if (format[c_i] != '.')
		return (prec);

	prec = 0;

	for (c_i += 1; format[c_i] != '\0'; c_i++)
	{
		if (is_digit(format[c_i]))
		{
			prec *= 10;
			prec += format[c_i] - '0';
		}
		else if (format[c_i] == '*')
		{
			c_i++;
			prec = va_arg(list, int);
			break;
		}
		else
			break;
	}

	*n = c_i - 1;

	return (prec);
}

