#include "main.h"

/**
 * _printf-produces output according to a format
 *
 * @format:formats used
 * Return: Total number of characters printed
 */
int _printf(const char *format, ...)
{
	va_list list;
	int i = 0, len, sum, j;
	int (*f_pointer)(va_list);

	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
			if (format[i + 1] > 48 && format[i + 1] <= 57)
			{
				for (j = 0; j < format[i + 1] - 48; j++)
				{
					write(1, " ", 1);
				}
				format++;
			}
			if (format[i + 2] > 48 && format[i + 2] <= 57 && format[i + 3] == 'd')
			{
				for (j = 0; j < format[i + 2] - 48; j++)
				{
					write(1, &format[i + 1], 1);
				}
				format += 2;
			}
			f_pointer = get_function(format[i + 1]);
			if (f_pointer != NULL)
			{
				len = f_pointer(list);
				sum += len;
				i += 2;
			}
			else
			{
				write(1, &format[i], 1);
				sum++;
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
