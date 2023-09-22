#ifndef MAIN_H
#define MAIN_H

/* header files */
#include <stdarg.h>
#include <stdlib.h>
#include <unistd.h>

/**
 * struct character_print - print data
 * @c: character.
 * @f_pr: function pointer
 */
typedef struct character_print
{
	char *c;
	int (*f_pr)(va_list arg);
} print_d;

/* function prototypes */
int _printf(const char *format, ...);
int _putchar(char c);
int pc(va_list arg);
int ps(va_list arg);
int pp(va_list arg __attribute((unused)));

int dc(va_list arg);
int print_dig(long int k, long int n);
int dcu(va_list arg);
int print_dig_u(long int k, long int n);
int bc(va_list arg);
int print_binary(long int k, long int n);
int print_rot13_string(char *c);

/* Add these function prototypes to your main.h file */

/* Function prototypes for print handlers in functions1.c */
int print_unsigned(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_octal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexadecimal(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa_upper(va_list types, char buffer[], int flags, int width, int precision, int size);
int print_hexa(va_list types, char map_to[], char buffer[], int flags, char flag_ch, int width, int precision, int size);


#endif /* MAIN_H */
