#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

typedef struct character_print
{
	char *c;
	int (*f_pr)(va_list arg);
} print_d;

#define F_ZERO 1
#define F_MINUS 2
#define F_PLUS 4
#define F_SPACE 8
#define F_HASH 16

int print_char(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_string(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_percent(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_int(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_binary(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_pointer(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_non_printable(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_reverse(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_rot13string(va_list types, char buffer[], int flags, int width, int precision, int size);

int get_flags(const char *format, int *i);
int get_precision(const char *format, int *i, va_list list);
int get_size(const char *format, int *i);
int get_width(const char *format, int *i, va_list list);

int handle_print(const char *fmt, int *ind, va_list list, char buffer[],
 int flags, int width, int precision, int size);

int is_printable(char c);
int append_hexa_code(char ascii_code, char buffer[], int i);
int is_digit(char c);
long int convert_size_number(long int num, int size);
long int convert_size_unsgnd(unsigned long int num, int size);

int handle_write_char(char c, char buffer[],
 int flags, int width, int precision, int size);

int write_number(int is_negative, int ind, char buffer[],
 int flags, int width, int precision, int size);

int write_unsgnd(int is_negative, int ind,
 char buffer[],
 int flags, int width, int precision, int size);

int write_pointer(char buffer[], int ind, int length,
 int width, int flags, char padd, char extra_c, int padd_start);

#endif
