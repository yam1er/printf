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
