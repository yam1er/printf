#include "main.h"
#include <stdio.h>

int main(void)
{
	char c;

	_printf("I am the one and %c.\n");
	printf("I am the one and %c.\n");
	_printf("I am the one and %c.\n", c);
	printf("I am the one and %c.\n", c);
	_printf("I am the one and .\n");
	printf("I am the one and .\n");
	return (0);
}
