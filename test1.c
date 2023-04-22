#include "main.h"

/**
 * main-tests _print_f
 *
 * Return:always 0
 */
int main(void)
{
	_printf("Test_1:\t%s\n", "Chaveuoooo");
	_printf("Test_2:\t%s\n", "Chavez");
	_printf("Test_3:\t%c\n%s\n", 'C', "nope");
	_printf("Test_4:\t%%%c\n", 'C');
	_printf("Test_5:\t%s%c\n", "hello", 'B');
	_printf("Test_6:\t%c\n", 'C');
	_printf("Test_7:\t%c\n", 'C');
	_printf("Test_8:\t%c\n", 'C');
	_printf("Test_9:\t%c\n", 'C');
	return (0);
}
