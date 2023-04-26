#include "main.h"
#include <stdarg.h>

/**
 * _print - converts integer values to string then prints
 * @holder: holds integer to be converted
 * Return: nothing
 */
int _print(int holder)
{
	char buffer[32];
	int i = 0;
	int count = 0;

	if (holder == 0)
	{
		_putchar('0');
		return (1);
	}

	while (holder > 0)
	{
		buffer[i++] = holder % 10 + '0';
		holder /= 10;
	}

	while (--i >= 0)
	{
		count++;
		_putchar(buffer[i]);
	}
	return (count);
}

/**
 * _print_int - prints d and i conversion specifiers
 *
 * @str: a charcter string
 * Return: the number of characters printed
 */
int _print_int(const char *str, ...)
{
	int holder;
	va_list list;
	const char *ptr;
	int count = 0;

	if (str == NULL)
		return (-1);

	va_start(list, str);

	for  (ptr = str; *ptr != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
				return (-1);

			else if (*ptr == 'd' || *ptr == 'i')
			{
				holder = va_arg(list, int);
				count += _print(holder);
			}
			else
			{
				return (-1);
			}
		}
		else
		{
			_putchar(*ptr);
			count++;
		}
	}
	va_end(list);
	return (count);
}
