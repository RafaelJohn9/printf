#include "main.h"

/**
 * _strlen - determines the length of a string
 *
 * @str: string to be counted
 * Return: length of str
 */

int _strlen(const char *str)
{
	const char *ptr;

	ptr = str;
	for (; *ptr; ptr++)
	{

	}

	return (ptr - str);
}

/**
 * print_percent - prints percentage sign
 *
 * @list: Arguments
 * Return: number of printed chars.
 */
int print_percent(va_list list)
{
	(void)list;

	write(1, "%", 1);
	return (1);
}

/**
 * printint - prints given integers
 *
 * @list: passed arguments
 * Return: Total number of integers printed
 */
int printint(va_list list)
{
	int holder;

	holder = va_arg(list, int);
	if (holder < 0)
	{
		write(1, "-", 1);
		holder = -holder;
		return (_print_int("%d", holder) + 1);
	}

	return (_print_int("%d", holder));
}

/**
 * printstr - prints string
 *
 * @list: passed argument
 * Return: Total characters printed
 */
int printstr(va_list list)
{
	int length = 0;
	char *str;

	str = va_arg(list, char *);
	if (str == NULL)
		str = "(null)";
	length = _strlen(str);

	write(1, str, length);

	return (length);
}

/**
 * printchar - prints a given  character
 *
 * @list: Arguments passed
 * Return: Number of chars printed
 */
int printchar(va_list list)
{
	unsigned char chr;

	chr = va_arg(list, int);
		write(1, &chr, 1);

	return (1);
}
