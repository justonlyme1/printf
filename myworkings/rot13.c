#include "main.h"
#include <stdio.h>

/**
 * print_rot13_string - Print a string using ROT13 cipher
 * @str: The input string
 *
 * Return: Number of characters printed
 */
int print_rot13_string(char *str)
{
	int printed_chars = 0;

	while (*str)
{
	char c = *str;

	if ((c >= 'A' && c <= 'Z') || (c >= 'a' && c <= 'z'))
{
	char base = (c >= 'a') ? 'a' : 'A';
	char rotated = (((c - base) + 13) % 26) + base;
		putchar(rotated);
		printed_chars++;
}
	else
{
	putchar(c);
	printed_chars++;
}
	str++;

	}
	return (printed_chars);
}
