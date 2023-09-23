#ifndef MAIN_H
#define MAIN_H

#include <stdlib.h>
#include <stddef.h>
int _printf(const char *format, ...);
int print_binary(unsigned int num);
int write_unsigned_int(unsigned int num);
int write_small_hexadecimal(unsigned int num);
int write_big_hexadecimal(unsigned int num);
int write_octal(unsigned int num);
int write_custom_S(char *str);
int write_pointer(void *p);
int write_rot13(char *str);
/*char *handle_first_flags(const char *format);*/

#endif
