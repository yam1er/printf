#include "main.h"
#include <unistd.h>
#include <stdio.h>


/**
 * print_binary - integer in binary format
 * @num: unsigned int to convert in binary format
 *
 * Return: number of caracter printed
 */

int print_binary(unsigned int num)
{
	char buffer[32];
	int i = 0, count;

	if (num == 0)
	{
		write(1, "0", 1);
		return (1);
	}

	while (num > 0)
	{
		buffer[i] = (num & 1) + '0';
		num >>= 1;
		i++;
	}

	count = i;
	while (i > 0)
	{
		i--;
		write(1, &buffer[i], 1);
	}
	return (count);
}

/**
 * write_unsigned_int - Print unsigned number
 * @num: number to write to output
 * Return: Number of char sent
 */

int write_unsigned_int(unsigned int num)
{
	char buffer[20];
	int len;

	len = snprintf(buffer, sizeof(buffer), "%u", num);
	write(1, buffer, len);
	return (len);
}

/**
 * write_small_hexadecimal - print hexdecimal with small letter
 * @num: number to output
 * Return: Number of caracter
 */

int write_small_hexadecimal(unsigned int num)
{
	char buffer[20];
	int len;

	len = snprintf(buffer, sizeof(buffer), "%x", num);
	write(1, buffer, len);
	return (len);
}

/**
 * write_big_hexadecimal - print hexadecimal with cap letters
 * @num: number to output
 * Return: Number of character printed out
 */
int write_big_hexadecimal(unsigned int num)
{
	char buffer[20];
	int len;

	len = snprintf(buffer, sizeof(buffer), "%X", num);
	write(1, buffer, len);
	return (len);
}

/**
 * write_octal - print number in octal
 * @num: Number to print
 * Return: Number of character printed out
 */
int write_octal(unsigned int num)
{
	char buffer[20];
	int len;

	len = snprintf(buffer, sizeof(buffer), "%o", num);
	write(1, buffer, len);
	return (len);
}

/**
 * write_custom_S - print non printable caracter
 * @str: string to handle
 *
 * Return: number of caracter printed
 */

int write_custom_S(char *str)
{
	int count;

	while (*str != '\0')
	{
		if (*str < 32 || *str >= 127)
		{
			char hex[5];

			snprintf(hex, sizeof(hex), "\\x%02X", (unsigned char)*str);
			write(1, hex, 4);
			count += 4;
		} else
		{
			write(1, str, 1);
			count++;
		}
		str++
	}
	return (count);
}
