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
	int i = 0, len;
	int sum = 0;
	int (*f_pointer)(va_list);

	if (format == NULL)
	{
		return (0);
	}
	va_start(list, format);
	while (format && format[i])
	{
		if (format[i] == '%')
		{
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
