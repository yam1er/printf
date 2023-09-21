#include "main.h"
#include <stdio.h>
#include <unistd.h>

/**
 * write_custom_S - Acustom specifier
 * @str: Pointer to string
 * Return: Number of character printed
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
		str++;
	}
	return (count);
}

/**
 * write_pointer - Print a pointer value
 * @p: Pointer
 * Return: Number of character printed
 */
int write_pointer(void *p)
{
	char buffer[20];
	int len;

	len = snprintf(buffer, sizeof(buffer), "%p", p);
	write(1, buffer, len);
	return (len);
}
