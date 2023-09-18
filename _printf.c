#include <stdarg.h>
#include "main.h"
#include <unistd.h>

/**
* _printf - Custom printf function
* @format: String format
* Return: Number of printed characters
*/

int _printf(const char *format, ...)
{
    va_list args;
    int count = 0;
    char c, percent = '%';
    char *str;

    va_start(args, format);
    while(*format != '\0')
    {
        if(*format == '%')
        {
            format++;
            if (*format == 'c')
            {
                c = va_arg(args, int);
                write(1, &c, 1);
                count++;
            } else if (*format == 's')
            {
                str = va_arg(args, char *);
                while(*str != '\0')
                {
                    write(1, str, 1);
                    str++;
                    count++;
                }
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
    return count;
}
