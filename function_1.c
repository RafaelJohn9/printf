#include "main.h"
#include <stdarg.h>
#include <string.h>
#include <unistd.h>
#include <stdlib.h>
#include <stdint.h>


/**
 * _printf-produces output according to a format
 * @format:formats used
 * Return: int type 
 */
int _printf(const char *format, ...)
{
	char x;
	int sum = 0;
	int i = 0;
	va_list list;

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				x = (char) va_arg(list, int);
				write(1, &x, 1);
				sum++;
			}
			else if (format[i + 1] == 's')
			{
				write(1, va_arg(list, char *), sizeof(char *));
				sum++;
			}
			else if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				sum++;
			}
			else
			{
				write(1, &format[i], 1);
				continue;
			}
		}
		else if (format[i - 1] != '%')
		{
			write(1, &format[i], 1);
		}
		i++;
	}
	va_end(list);
	return (sum);
}
