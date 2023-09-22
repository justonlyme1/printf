#include "main.h"

/* Custom putchar function declaration */
int _putchar(char c);

/**
 * _printf - Custom printf function
 * @format: The format string
 *
 * Return: The number of characters printed.
 */
int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;

    va_start(args, format);

    while (format && format[count])
    {
        if (format[count] != '%')
        {
            _putchar(format[count]);
            count++;
        }
        else
        {
            count++; /*Move past the '%'*/
            switch (format[count])
            {
                case 'c':
                    _putchar(va_arg(args, int));
                    break;
                case 's':
                {
                    char *str = va_arg(args, char *);
                    if (str)
                    {
                        while (*str)
                        {
                            _putchar(*str);
                            str++;
                        }
                    }
                    else
                    {
                        _putchar('(');
                        _putchar('n');
                        _putchar('u');
                        _putchar('l');
                        _putchar('l');
                        _putchar(')');
                    }
                    break;
                }
                case '%':
                    _putchar('%');
                    break;
		case 'd':
                case 'i':
                {
                    int num = va_arg(args, int);
                    /* Call the print_integer function from print_integer.c*/
                    print_integer(num);
                    break;
                }

		case 'b': /*Handle the %b conversion specifier*/
                {
                    unsigned int num = va_arg(args, unsigned int);
                    print_binary(num);
                    break;
		}
                default:
                    _putchar('%');
                    _putchar(format[count]);
            }
            count++;
        }
    }

    va_end(args);

    return count;
}
