#include "main.h"
#include <stdarg.h>
#include <unistd.h>

/**
 * _printf - printf function
 * @format: format
 * Return: printed chars.
 */
int _printf(const char *format, ...)
{
	int printed_chars = 0;
	va_list list;
	char buffer[BUFF_SIZE];
	int buff_ind = 0; // Initialize buffer index to 0

	if (format == NULL)
		return (-1);

	va_start(list, format);

	for (int i = 0; format[i] != '\0'; i++)
	{
		if (format[i] != '%')
		{
			buffer[buff_ind++] = format[i];
			if (buff_ind == BUFF_SIZE)
			{
				print_buffer(buffer, &buff_ind);
				printed_chars += BUFF_SIZE;
			}
			else
			{
				printed_chars++;
			}
		}
		else
		{
			print_buffer(buffer, &buff_ind);
			int flags = get_flags(format, &i);
			int width = get_width(format, &i, list);
			int precision = get_precision(format, &i, list);
			int size = get_size(format, &i);
			i++;
			int printed = handle_print(format, &i, list, buffer,
			                           flags, width, precision, size);
			if (printed == -1)
				return (-1);
			printed_chars += printed;
		}
	}
	print_buffer(buffer, &buff_ind);
	va_end(list);
	return (printed_chars);
}

/**
 * print_buffer - print contents
 * @buffer: array of chars
 * @buff_ind: index
 */
void print_buffer(char buffer[], int *buff_ind)
{
	if (*buff_ind > 0)
	{
		write(1, buffer, *buff_ind); // Write the entire buffer at once
		*buff_ind = 0; // Reset buffer index
	}
}
