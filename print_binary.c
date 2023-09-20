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
	char buffer[1024];
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
