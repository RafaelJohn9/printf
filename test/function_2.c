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

	if (holder == 0)
	{
		_putchar('0');
		return;
	}

	while (holder > 0)
	{
		buffer[i++] = holder % 10 + '0';
		holder /= 10;
	}

	while (--i >= 0)
	{
		_putchar(buffer[i]);
	}
}

/**
 * _print_int - prints d and i conversion specifiers
 *
 * @str: a charcter string
 * Return: the number of characters printed
 */
int _print_int(const char *str, ...)
{
	int count = 0;
	int holder;
	va_list list;
	char *ptr;

	if (str == NULL)
		return (-1);
	ptr = str;
	va_start(list, str);

	for  (; *str != '\0'; ptr++)
	{
		if (*ptr == '%')
		{
			ptr++;
			if (*ptr == '\0')
				return (-1);

			else if (*str == 'd' || *str == 'i')
			{
				holder = va_arg(list, int);
				_print(holder);
				count++;
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
