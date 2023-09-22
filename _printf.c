#include <stdio.h>
#include <stdarg.h>
#include "main.h"
#include <unistd.h>

int write_char(char c);
int write_string(char *str);
int write_integer(int num, char *flags);

/**
* _printf - Custom printf function
* @format: String format
* Return: Number of printed characters
*/

int _printf(const char *format, ...)
{
	va_list args;
	int count = 0, i;
	unsigned int num;
	char c, percent = '%', *str;
	void *p;
	char *flags;

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

			flags = handle_first_flags(format);

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
			} else if (*format == 'i' || *format == 'd')
			{
				num = va_arg(args, int);
				count += write_integer(num, flags);
			} else if (*format == 'b')
			{
				num = va_arg(args, unsigned int);
				count += print_binary(num);
			} else if (*format == 'u')
			{
				num = va_arg(args, unsigned int);
				count += write_unsigned_int(num);
			} else if (*format == 'x')
			{
				num = va_arg(args, unsigned int);
				count += write_small_hexadecimal(num);
			} else if (*format == 'X')
			{
				num = va_arg(args, unsigned int);
				count += write_big_hexadecimal(num);
			} else if (*format == 'o')
			{
				num = va_arg(args, unsigned int);
				count += write_octal(num);
			} else if (*format == 'S')
			{
				str = va_arg(args, char *);
				count += write_custom_S(str);
			} else if (*format == 'p')
			{
				p = va_arg(args, void *);
				count += write_pointer(p);
			} else
			{
				for (i = 0; i < 2; i++)
				{
					write(1, format - 1 + i, 1);
					count++;
				}
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

	if (str == NULL)
	{
		str = "(null)";
	}
	while (*str != '\0')
	{
		write(1, str, 1);
		str++;
		count++;
	}
	return (count);
}

/**
 * write_integer - hold %i and %d (Mantynou)
 * @num: number or characters to write to stdout
 * @flags: flags to handle adress
 * Return: Number of char send to the stdout
 */

int write_integer(int num, char *flags)
{
	char buffer[20];
	int len;

	len = snprintf(buffer, sizeof(buffer), "%s%d",
(flags[0] == '+' && num >= 0)
? "+" : (flags[0] == ' ' && num >= 0) ? " " : "", num);
	write(1, buffer, len);
	return (len);
}
