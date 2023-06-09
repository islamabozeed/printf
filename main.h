#ifndef MAIN_H
#define MAIN_H

#include <stdarg.h>
#include <stdio.h>
#include <unistd.h>

#define UNUSED(x) (void)(x)
#define BUFFER_SIZE 1024

#define MINUS_FLAG 1
#define PLUS_FLAG 2
#define ZERO_FLAG 4
#define HASH_FLAG 8
#define SPACE_FLAG 16

#define LONG_SIZE 2
#define SHORT_SIZE 1

/**
 * struct format - Struct op
 * @fmt: The format.
 * @fn: The function that will be called.
 */
struct format
{
	char fmt;
	int (*fn)(va_list, char[], int, int, int, int);
};

/**
 * typedef struct format fmt_t - Struct op
 * @fmt: The format.
 * @fm_t: The function that will be called.
 */
typedef struct format fmt_t;

int _printf(const char *format, ...);
int handle_print(const char *fmt, int *i,
va_list list, char buffer[], int flags, int width, int precision, int size);

/* Functions Prototypes */

/* Funtions that print chars and strings */
int chr(va_list typ, char buff[],
	int flg, int wd, int prc, int size);
int p(va_list typ, char buff[],
	int flg, int wd, int prc, int size);
int percent(va_list typ, char buff[],
	int flg, int wd, int prc, int size);

/* Functions that print numbers */
int integer(va_list typ, char buff[],
	int flg, int wd, int prc, int size);
int binary(va_list typ, char buff[],
	int flg, int wd, int prc, int size);
int print_unsigned(va_list typ, char buff[],
	int flag, int w, int prec, int size);
int print_octal(va_list typ, char buff[],
	int flag, int w, int prec, int size);
int print_hexadecimal(va_list typ, char buff[],
	int flag, int w, int prec, int size);
int print_hexa_upper(va_list typ, char buff[],
	int flag, int w, int prec, int size);

int print_hexa(va_list typ, char map_to[],
char buff[], int flag, char flag_ch, int w, int prec, int size);

/* Function that print non printable characters */
int print_non_printable(va_list typ, char buff[],
	int flag, int w, int prec, int size);

/* Funcion that print memory addresses */
int pointer(va_list typ, char buff[],
	int flag, int w, int prec, int size);

/* Functions that handle other specifiers */
int get_flags(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);
int get_prec(const char *format, int *i, va_list list);
int get_space(const char *format, int *i);

/* Function that print string in reverse */
int print_reverse(va_list typ, char buff[],
	int flag, int w, int prec, int size);

/* Function that print a string in rot 13 */
int print_rot13string(va_list typ, char buff[],
	int flag, int w, int prec, int size);

/* Width Handler */
int handle_write_char(char c, char buffer[],
	int flags, int width, int precision, int size);
int write_number(int is_positive, int ind, char buffer[],
	int flags, int width, int precision, int size);
int write_num(int ind, char bff[], int flags, int width, int precision,
	int length, char padd, char extra_c);
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start);

int write_unsigned(int is_negative, int ind,
char buffer[],
	int flags, int width, int precision, int size);

/* Utils */
int is_printable(char);
int append_hexa_code(char, char[], int);
int is_digit(char);

long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

void print_buffer(char buffer[], int *buff_ind);

#endif /* MAIN_H */
