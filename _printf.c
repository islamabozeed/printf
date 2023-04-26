#include "main.h"

/**
 * _printf - Printf's function.
 * @format: format(data types)
 * Return: Always return 0
 */
int _printf(const char *format, ...)
{
	int n, p = 0, p_chars = 0;
	int f, w, prec, z, buff = 0;
	va_list list;
	char buffer[BUFFER_SIZE];

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (n = 0; format && format[n] != '\0'; n++)
	{
		if (format[n] != '%')
		{
			buffer[buff++] = format[n];
			if (buff == BUFFER_SIZE)
				print_buffer(buffer, &buff);
			p_chars++;
		}
		else
		{
			print_buffer(buffer, &buff);
			f = get_flags(format, &n);
			w = get_width(format, &n, list);
			prec = get_prec(format, &n, list);
			z = get_space(format, &n);
			++n;
			p = handle_print(format, &n, list, buffer,
					f, w, prec, z);
			if (p == -1)
				return (-1);
			p_chars += p;
		}
	}
	print_buffer(buffer, &buff);
	va_end(list);
	return (p_chars);
}
/**
 * print_buffer - check if buffer content is exist
 * @buffer: Array
 * @buff_ind: the length
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
		write(1, &buffer[0], *buff_ind);

	*buff_ind = 0;
}
