// printf_functions.c
#include "main.h"

int print_c(va_list arg)
{
    /*Custom function to print 'c'*/
    int c = va_arg(arg, int);
    _putchar(c);
    return 1;
}

int print_s(va_list arg)
{
    char *str = va_arg(arg, char *);
    int printed_chars = 0;

    if (str)
    {
        while (*str)
        {
            _putchar(*str);
            printed_chars++;
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
        printed_chars += 6;
    }

    return printed_chars;
}



    /* Custom function to print 'd' or 'i'*/
int print_d(va_list arg)
{
    int num = va_arg(arg, int);
    int printed_chars = 0;

    /* Handle negative numbers*/
    if (num < 0)
    {
        _putchar('-');
        printed_chars++;
        num = -num;
    }

    /* Handle the case when num is zero*/
    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
    }
    else
    {
        char buffer[12]; /*Assuming a maximum of 12 digits for an int (including sign)*/
        int index = 0;

        /*Extract and store digits in reverse order*/
        while (num > 0)
        {
            buffer[index++] = num % 10 + '0';
            num /= 10;
        }

        /* Print digits in correct order*/
        while (--index >= 0)
        {
            _putchar(buffer[index]);
            printed_chars++;
        }
    }

    return printed_chars;
}


int print_b(va_list arg)
{
    /* Custom function to print 'b'*/
    unsigned int num = va_arg(arg, unsigned int);
    /* ... (implementation for 'b') ...*/
}
int print_u(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    int printed_chars = 0;

    /*Handle the case when num is zero*/
    if (num == 0)
    {
        _putchar('0');
        printed_chars++;
    }
    else
    {
        /*Call the print_unsigned function to print the unsigned integer*/
        print_unsigned(num);
    }

    return printed_chars;
}

int print_o(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    int printed_chars = 0;

    /*Call the print_octal function to print the octal number*/
    print_octal(num);

    return printed_chars;
}

int print_x(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    int printed_chars = 0;

    /* Call the print_hexadecimal function with lowercase option*/
    print_hexadecimal(num, 0);

    return printed_chars;
}

int print_X(va_list arg)
{
    unsigned int num = va_arg(arg, unsigned int);
    int printed_chars = 0;

    /* Call the print_hexadecimal function with uppercase option*/
    print_hexadecimal(num, 1);

    return printed_chars;
}


/* Define an array of print_d structs to map format specifiers to functions*/
print_d format_functions[] = {
    {"c", print_c},
    {"s", print_s},
    {"d", print_d},
    {"i", print_d},
    {"b", print_b},
	{"u", print_u},
    {"o", print_o},
    {"x", print_x},
    {"X", print_X},
    {NULL, NULL} /*End of array marker*/
};
