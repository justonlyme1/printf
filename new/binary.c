#include "main.h"

/**
 * print_binary - Custom function to print an unsigned int in binary
 * @num: The unsigned integer to print in binary
 *
 * This function prints an unsigned int in binary format.
 */
void print_binary(unsigned int num)
{
    int binary[32]; // Assuming 32-bit integers
    int index = 0;

    /*Convert the integer to binary representation*/
    while (num > 0)
    {
        binary[index++] = num % 2;
        num /= 2;
    }

    /*Print binary representation in reverse order*/
    while (--index >= 0)
    {
        _putchar(binary[index] + '0');
    }
