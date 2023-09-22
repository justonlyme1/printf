#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdarg.h>

/**define the print_d struct
*typedef struct character_print you've defined appears
*to be a data structure that associates a character
*(or a string) with a function pointer that takes a
*va_list argument
***/
typedef struct character_print
{
    char *c;
    int (*f_pr)(va_list arg);
} print_d;

int _printf(const char *format, ...);
void print_integer(int num);
void print_binary(unsigned int num);
void print_unsigned(unsigned int num);
void print_octal(unsigned int num);
void print_hexadecimal(unsigned int num, int uppercase);


#endif /* MAIN_H */
