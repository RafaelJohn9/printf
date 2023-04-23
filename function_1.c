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
	unsigned char x;
	int sum = 0, i = 0, a = 0, num;
	va_list list;
	char *str;

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] == 'c')
			{
				x = (unsigned char)va_arg(list, int);
				if (x)
				{
					write(1, &x, 1);
					sum++;
					i = i + 2;
				}
				else
				{
					return (0);
				}
			}
			else if (format[i + 1] == 's')
			{
				str = va_arg(list, char *);
				if (str)
				{
					write(1, str, strlen(str));
					sum =sum + strlen(str);
					i = i + 2;
				}
				else
				{
					return (0);
				}
			}
			else if (format[i + 1] == '%')
			{
				write(1, &format[i + 1], 1);
				sum++;
				i = i + 2;
			}
			else if (format[i + 1] == 'd' || format[i + 1] == 'i')
			{
				num = va_arg(list, int);
				if (num)
				{
					a =_print_int(format + i,num);
					sum += a;
					i += 2;
				}
				else
				{
					return (0);
				}
			}
			else
			{
				write(1, &format[i], 1);
				i++;
			}
		}
		else
		{
			write(1, &format[i], 1);
			sum++;
			i++;
		}
	}
	va_end(list);
	return (sum);
}	
