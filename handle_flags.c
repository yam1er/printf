#include "main.h"


/**
 * handle_first_flags - manage *, space and # flags
 * @format: mandatory argument
 *
 * Return: array storing flags
 */

char *handle_first_flags(const char *format)
{
	char *flags = NULL;

	flags = malloc(4);
	if (flags == NULL)
		return (NULL);
	while (*format == '+' || *format == ' ' || *format == '#')
	{
		*flags++ = *format;
		format++;
	}
	*flags = '\0';

	return (flags);
}
