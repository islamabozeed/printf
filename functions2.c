#include "main.h"
/**
 * pointer - Print pointer
 * @typ: types
 * @buff: buffer
 * @flag: flags
 * @w: get w
 * @prec: Precision
 * @size: size
 * Return: Always 0
 */
int pointer(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{
	char extra_c = 0, padd = ' ';
	int ind = BUFFER_SIZE - 2, length = 2, padd_start = 1;
	unsigned long num_addrs;
	char map_to[] = "0123456789abcdef";
	void *addrs = va_arg(typ, void *);

	UNUSED(w);
	UNUSED(size);

	if (addrs == NULL)
		return (write(1, "(nil)", 5));

	buff[BUFFER_SIZE - 1] = '\0';
	UNUSED(prec);

	num_addrs = (unsigned long)addrs;

	while (num_addrs > 0)
	{
		buff[ind--] = map_to[num_addrs % 16];
		num_addrs /= 16;
		length++;
	}

	if ((flag & ZERO_FLAG) && !(flag & MINUS_FLAG))
		padd = '0';
	if (flag & PLUS_FLAG)
		extra_c = '+', length++;
	else if (flag & SPACE_FLAG)
		extra_c = ' ', length++;

	ind++;
	return (write_pointer(buff, ind, length,
		w, flag, padd, extra_c, padd_start));
}
/**
 * non_printable - non printable's
 * @typ: types
 * @buff: buffer
 * @flag:  flags
 * @w: get w
 * @prec: Precision
 * @size: size
 * Return: Always 0
 */
int print_non_printable(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{
	int i = 0, offset = 0;
	char *str = va_arg(typ, char *);

	UNUSED(flag);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		return (write(1, "(null)", 6));

	while (str[i] != '\0')
	{
		if (is_printable(str[i]))
			buff[i + offset] = str[i];
		else
			offset += append_hexa_code(str[i], buff, i + offset);

		i++;
	}

	buff[i + offset] = '\0';

	return (write(1, buff, i + offset));
}
/**
 * print_reverse - Print reverse string.
 * @typ: types
 * @buff: buffer
 * @flag:  flags
 * @w: get w
 * @prec: Precision
 * @size: size
 * Return: Always 0
 */

int print_reverse(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{
	char *str;
	int i, count = 0;

	UNUSED(buff);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(size);

	str = va_arg(typ, char *);

	if (str == NULL)
	{
		UNUSED(prec);

		str = ")Null(";
	}
	for (i = 0; str[i]; i++)
		;

	for (i = i - 1; i >= 0; i--)
	{
		char z = str[i];

		write(1, &z, 1);
		count++;
	}
	return (count);
}
/**
 * print_rot13string - Print of the string in rot13.
 * @typ: types
 * @buff: buffer
 * @flag:  flags
 * @w: get w
 * @prec: Precision
 * @size: size
 * Return: Always 0
 */
int print_rot13string(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{
	char x;
	char *str;
	unsigned int i, j;
	int count = 0;
	char in[] = "ABCDEFGHIJKLMNOPQRSTUVWXYZabcdefghijklmnopqrstuvwxyz";
	char out[] = "NOPQRSTUVWXYZABCDEFGHIJKLMnopqrstuvwxyzabcdefghijklm";

	str = va_arg(typ, char *);
	UNUSED(buff);
	UNUSED(flag);
	UNUSED(w);
	UNUSED(prec);
	UNUSED(size);

	if (str == NULL)
		str = "(AHYY)";
	for (i = 0; str[i]; i++)
	{
		for (j = 0; in[j]; j++)
		{
			if (in[j] == str[i])
			{
				x = out[j];
				write(1, &x, 1);
				count++;
				break;
			}
		}
		if (!in[j])
		{
			x = str[i];
			write(1, &x, 1);
			count++;
		}
	}
	return (count);
}

