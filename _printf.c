#include <stdarg.h>
#include "main.h"
#include <unistd.h>

int write_char(char c);
int write_string(char *str);
/**
* _printf - Custom printf function
* @format: String format
* Return: Number of printed characters
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0;
	char c, percent = '%', *str;

	if (format == NULL)
	{
		return (-1);
	}
	va_start(args, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 'c')
			{
				c = va_arg(args, int);
				count += write_char(c);
			} else if (*format == 's')
			{
				str = va_arg(args, char *);
				count += write_string(str);
			} else if (*format == '%')
			{
				write(1, &percent, 1);
				count++;
			} else
			{
				write(1, format, 1);
				count++;
			}
		} else
		{
			write(1, format, 1);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
 * write_char - Write char
 * @c: Char to write
 * Return: Number of char written
 */
int write_char(char c)
{
	int  count = 0;

	write(1, &c, 1);
	count++;
	return (count);
}

/**
 * write_string - Write string to stdout
 * @str: Pointer to string to write to stdout
 * Return: Number of char sent to the stdout
 */
int write_string(char *str)
{
	int count = 0;

	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}
