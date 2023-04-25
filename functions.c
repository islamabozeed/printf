#include "main.h"

/**
 * chr - char function
 * @typ: arg
 * @buff: array
 * @flg:  flag
 * @wd: Width
 * @prc: prc
 * @size: size
 * Return: Always 0
 */
int chr(va_list typ, char buff[],
		int flg, int wd, int prc, int size)
{
	char ch = va_arg(typ, int);

	return (handle_write_char(ch, buff, flg, wd, prc, size));
}

/**
 * p - this function prints string
 * @typ: arg
 * @buff: array
 * @flg:  Evaluates effective flg
 * @wd: get wd.
 * @prc: prc
 * @size: size
 * Return: Always 0
 */

int p(va_list typ, char buff[],
		int flg, int wd, int prc, int size)
{
	int n = 0, i;
	char *p = va_arg(typ, char *);

	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wd);
	UNUSED(prc);
	UNUSED(size);
	if (p == NULL)
	{
		p = "(null)";
		if (prc >= 6)
			p = "      ";
	}

	while (p[n] != '\0')
		n++;

	if (prc >= 0 && prc < n)
		n = prc;

	if (wd > n)
	{
		if (flg & MINUS_FLAG)
		{
			write(1, &p[0], n);
			for (i = wd - n; i > 0; i--)
				write(1, " ", 1);
			return (wd);
		}
		else
		{
			for (i = wd - n; i > 0; i--)
				write(1, " ", 1);
			write(1, &p[0], n);
			return (wd);
		}
	}

	return (write(1, p, n));
}
/**
 * percent - Print percent sign
 * @typ: arg
 * @buff: array
 * @flg:  Evaluates effective flg
 * @wd: get wd.
 * @prc: prc
 * @size: size
 * Return: Always 0
 */

int percent(va_list typ, char buff[],
		int flg, int wd, int prc, int size)
{
	UNUSED(typ);
	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wd);
	UNUSED(prc);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
 * intger - Print int
 * @typ: arg
 * @buff: array
 * @flg:  Evaluates effective flg
 * @wd: get wd.
 * @prc: prc
 * @size: size
 * Return: Always 0
 */
int integer(va_list typ, char buff[],
		int flg, int wd, int prc, int size)
{
	int i = BUFFER_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(typ, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)
	{
		num = (unsigned long int)((-1) * n);
		is_negative = 1;
	}

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_number(is_negative, i, buff, flg, wd, prc, size));
}
/**
 * binary - Prints a binary
 * @typ: arg
 * @buff: array
 * @flg:  Evaluates effective flg
 * @wd: get wd.
 * @prc: prc
 * @size: size
 * Return: Always 0
 */
int binary(va_list typ, char buff[],
		int flg, int wd, int prc, int size)
{
	unsigned int n, m, i, sum;
	unsigned int a[32];
	int count;

	UNUSED(buff);
	UNUSED(flg);
	UNUSED(wd);
	UNUSED(prc);
	UNUSED(size);

	n = va_arg(typ, unsigned int);
	m = 2147483648; /* (2 ^ 31) */
	a[0] = n / m;
	for (i = 1; i < 32; i++)
	{
		m /= 2;
		a[i] = (n / m) % 2;
	}
	for (i = 0, sum = 0, count = 0; i < 32; i++)
	{
		sum += a[i];
		if (sum || i == 31)
		{
			char z = '0' + a[i];

			write(1, &z, 1);
			count++;
		}
	}
	return (count);
}

