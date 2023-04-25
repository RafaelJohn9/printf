#include "main.h"
#include <stdio.h>

/**
 * main - tests _printf
 *
 * Return: nothing
 */
int main(void)
{
	int num = 42;
	char chr = 'A';
	char str[] = "Mutumin banza";
	int p_count = 0, count;

	printf("printf: -------------------------------------\n");
	printf("The number %% is %d\n", num);
	printf("The number is %i\n", num);
	printf("The char is %c\n", chr);
	count = printf("The string is %s\n", str);
	printf("The return val is %d\n", count);




	printf("_printf: -------------------------------------\n");
	_printf("The number %% is %d\n", num);
	_printf("The number is %i\n", num);
	_printf("The char is %c\n", chr);
	p_count = _printf("The string is %s\n", str);
	printf("The return val is %d\n", p_count);

	printf("_printf: -------------------------------------\n");
	_print_int("The number is %d\n", num);
	_print_int("The number is %i\n", num);

	return (0);
}
