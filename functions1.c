#include "main.h"

/**
 * print_unsigned - unsigned number
 * @typ: arg
 * @buff: buffer
 * @flag:  flags
 * @w: get w
 * @prec: Precision
 * @size: Size
 * Return: Always 0
 */
int print_unsigned(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{
	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 10) + '0';
		num /= 10;
	}

	i++;

	return (write_unsgnd(0, i, buff, flag, w, prec, size));
}
/**
 * print_octal - Print unsigned number in octal notation
 * @typ: arg
 * @buff: buffer
 * @flag:  flags
 * @w: get w
 * @prec: Precision
 * @size: Size
 * Return: Always 0
 */
int print_octal(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{

	int i = BUFFER_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = (num % 8) + '0';
		num /= 8;
	}

	if (flag & HASH_FLAG && init_num != 0)
		buff[i--] = '0';

	i++;

	return (write_unsgnd(0, i, buff, flag, w, prec, size));
}
/**
 * print_hexadecimal - Print unsigned number in hexadecimal notation
 * @typ: arg
 * @buff: buffer
 * @flag:  flags
 * @w: get w
 * @prec: Precision
 * @size: Size
 * Return: Always 0
 */
int print_hexadecimal(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{
	return (print_hexa(typ, "0123456789abcdef", buff,
		flag, 'x', w, prec, size));
}
/**
 * print_hexa_upper - Print unsigned number in upper hexadecimal notation
 * @typ: arg
 * @buff: buffer
 * @flag:  flags
 * @w: get w
 * @prec: Precision
 * @size: Size
 * Return: Always 0
 */
int print_hexa_upper(va_list typ, char buff[],
	int flag, int w, int prec, int size)
{
	return (print_hexa(typ, "0123456789ABCDEF", buff,
		flag, 'X', w, prec, size));
}
/**
 * print_hexa - Print hexadecimal number in lower or upper
 * @typ: arg
 * @map_to: Array of values to map the number to
 * @buff: buffer
 * @flag: flags
 * @flag_ch: flags
 * @w: get w
 * @prec: Precision
 * @size: Size
 * @size: Size specification
 * Return: Always 0
 */
int print_hexa(va_list typ, char map_to[], char buff[],
	int flag, char flag_ch, int w, int prec, int size)
{
	int i = BUFF_SIZE - 2;
	unsigned long int num = va_arg(typ, unsigned long int);
	unsigned long int init_num = num;

	UNUSED(w);

	num = convert_size_unsgnd(num, size);

	if (num == 0)
		buff[i--] = '0';

	buff[BUFFER_SIZE - 1] = '\0';

	while (num > 0)
	{
		buff[i--] = map_to[num % 16];
		num /= 16;
	}

	if (flag & HASH_FLAG && init_num != 0)
	{
		buff[i--] = flag_ch;
		buff[i--] = '0';
	}

	i++;

	return (write_unsgnd(0, i, buff, flag, w, prec, size));
}

