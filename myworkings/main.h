#ifndef MAIN_H
#define MAIN_H

/* Include necessary header files */
#include <stdarg.h>  // For va_list and va_start
#include <stdlib.h>  // For malloc
#include <unistd.h>  // For write

/**
 * struct character_print - print data
 * @c: character specifier.
 * @f_pr: function pointer for print handler.
 */
typedef struct character_print
{
    char *c;
    int (*f_pr)(va_list arg, char *buffer, unsigned int ibuf);
} print_d;

/* Function prototypes for print handlers */
int _printf(const char *format, ...);
int _putchar(char c);
int pc(va_list arg, char *buffer, unsigned int ibuf);
int pp(va_list arg, char *buffer, unsigned int ibuf);
int ps(va_list arg, char *buffer, unsigned int ibuf);

/* More function prototypes for print handlers */
int print_dig(va_list arg, char *buffer, unsigned int ibuf);
int print_dig_u(va_list arg, char *buffer, unsigned int ibuf);
int print_binary(va_list arg, char *buffer, unsigned int ibuf);
int print_rot13_string(va_list arg, char *buffer, unsigned int ibuf);
int print_hex_lower(unsigned int n);


/* Function prototypes for utility functions */
int get_print_func(const char *format, unsigned int i);
int ev_print_func(const char *format, unsigned int i);
void handl_buf(char *buffer, char c, unsigned int ibuf);
void print_buf(char *buffer, unsigned int ibuf);

#endif /* MAIN_H */
