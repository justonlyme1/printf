#include "main.h"

/**
 * print_unsigned - Custom function to print an unsigned integer
 * @num: The unsigned integer to print
 *
 * This function prints an unsigned integer without using printf.
 */
void print_unsigned(unsigned int num)
{
    if (num == 0)
    {
        _putchar('0');
        return;
    }

    char buffer[12]; /*Assuming a maximum of 12 digits for an unsigned int*/
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
    }
}

/**
 * print_octal - Custom function to print an octal number
 * @num: The octal number to print
 *
 * This function prints an octal number without using printf.
 */
void print_octal(unsigned int num)
{
    char octal[12]; /*Assuming a maximum of 12 digits for an unsigned octal*/
    int index = 0;

    /*Extract and store octal digits in reverse order*/
    while (num > 0)
    {
        octal[index++] = num % 8 + '0';
        num /= 8;
    }

    /* Print octal digits in correct order*/
    while (--index >= 0)
    {
        _putchar(octal[index]);
    }
}

/**
 * print_hexadecimal - Custom function to print a hexadecimal number
 * @num: The hexadecimal number to print
 * @uppercase: Flag to print uppercase letters (1) or lowercase (0)
 *
 * This function prints a hexadecimal number without using printf.
 */
void print_hexadecimal(unsigned int num, int uppercase)
{
    char hex[12]; /*Assuming a maximum of 12 hexadecimal digits for an unsigned int*/
    int index = 0;

    while (num > 0)
    {
        int digit = num % 16;
        if (digit < 10)
        {
            hex[index++] = digit + '0';
        }
        else
        {
            hex[index++] = (uppercase) ? (digit - 10 + 'A') : (digit - 10 + 'a');
        }
        num /= 16;
    }

    /*Print hexadecimal digits in correct order*/
    while (--index >= 0)
    {
        _putchar(hex[index]);
    }
}
