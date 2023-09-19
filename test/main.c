#include <stdio.h>
#include "main.h"

/**
* main - Testing _printf function
* Return: Always 0.
*/
int main(void)
{
    char Name[] = "Alphonse";
    int char_printed;

    char_printed = _printf("Hello %s, today is %c, and your bat is 100%%.\n", Name, 'W');
    printf("You printed %d chars.\n", char_printed);
    return (0);
}
