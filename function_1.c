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
	intptr_t x;
	int sum = 0;
	int i = 0;
	va_list list;

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == 'c')
		{
			x = va_arg(list, intptr_t);
			write(1, (char *)x, strlen((char *)x));
			sum++;
		}
		else if (format[i] == 's')
		{
			x = va_arg(list, intptr_t);
			write(1, (char *)x, strlen((char *)x));
			sum++;
		}
		else
		{
			continue;
		}
		i++;
	}
	va_end(list);
	return (sum);
}
