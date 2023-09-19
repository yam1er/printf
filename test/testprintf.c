#include <stdio.h>

/**
 * Testing printf
 * Return: Always 0
 */
int main(void)
{
	char *str;
	char str2[] = {'\0'};
	int cp, cp2;

	cp = printf("My name is : %s.\n", str);
	cp2 = printf("My name is : %s.\n", str2);
	printf("cp: %d, cp2: %d.\n", cp, cp2);
	return (0);
}
