#include "main.h"

/**
 * get_function - Returns the appropriate function for a specifier
 *
 * @chr: Format specifier character
 *
 * Return: Function pointer for the specified format specifier, or NULL if
 *         no such format specifier exists
 */
int (*get_function(char chr))(va_list)
{
	int i;

	specifiers_t print_funcs[] = {
		{'c', printchar},
		{'s', printstr},
		{'%', print_percent},
		{'d', printint},
		{'i', printint},
		{'\0', NULL}
	};

	for (i = 0; print_funcs[i].print_val != NULL; i++)
	{
		if (print_funcs[i].spec == chr)
			return (print_funcs[i].print_val);
	}
	return (NULL);
}
