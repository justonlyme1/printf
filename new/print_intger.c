/* print_integer.c*/
#include "main.h"

/**
 * print_integer - Custom function to print an integer
 * @num: The integer to print
 *
 * This function prints an integer without using printf.
 */
void print_integer(int num)
{
    /* Handle negative numbers*/
    if (num < 0)
    {
        _putchar('-');
        num = -num;
    }

    /* Handle the case when num is zero*/
    if (num == 0)
    {
        _putchar('0');
        return;
    }

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
    }
}
