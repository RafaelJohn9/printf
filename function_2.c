#include "main.h"
#include <stdarg.h>

/**
 * _print - converts integer values to string then prints
 * @holder: holds integer to be converted
 * Return: nothing
 */
void _print(int holder)
{
	char buffer[32];
	int i = 0;

	if (holder < 0)
	{
		_putchar('-');
		holder = -holder;
	}
	do {
		buffer[i++] = holder % 10 + '0';
		holder /= 10;
	} while (holder > 0);

	while (--i >= 0)
	{
		_putchar(buffer[i]);
	}
}

/**
 * _print_int - prints d and i conversion specifiers
 *
 * @format: a charcter string
 * Return: the number of characters printed
 */
int _print_int(const char *str, ...)
{
	int count = 0;
	int holder;
	va_list list;

	va_start(list, str);

	while (*str != '\0')
	{
		if (*str == '%')
		{
			str++;
			if (*str == 'd' || *str == 'i')
			{
				holder = va_arg(list, int);
				_print(holder);
				count++;
			}
		}
		str++;
	}
	va_end(list);
	return (count);
}
