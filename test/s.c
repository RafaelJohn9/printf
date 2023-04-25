#include "main.h"

/**
 * string-checks for strings
 * @list:string to be checked
 * Return:sum + string length
 */
int string(va_list list)
{
	char *answer;
	int len;

	answer = va_arg(list, char *);
	if (answer == NULL)
	{
		write(1, "(null)", 6);
		return (6);
	}
	len = strlen(answer);
	write(1, answer, len);
	return (len);
}
