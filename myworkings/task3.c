#include "main.h"
#include <stdio.h>

/**
 * print_hex_lower - Print an unsigned integer in lowercase hexadecimal format
 * @n: The unsigned integer to print
 *
 * Return: Number of characters printed
 */
int print_hex_lower(unsigned int n)
{
    char hex_digits[] = "0123456789abcdef"; // Hexadecimal digits
    char buffer[20]; // Adjust the size as needed
    int len = 0;

    // Convert the unsigned integer to hexadecimal
    do
    {
        buffer[len++] = hex_digits[n % 16];
        n /= 16;
    } while (n > 0);

    // Print the characters in reverse order
    for (int i = len - 1; i >= 0; i--)
    {
        putchar(buffer[i]);
    }

    return (len);
}
