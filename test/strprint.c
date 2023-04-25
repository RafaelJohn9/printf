#include "main.h"

/**
 * _strprint - prints string
 *
 * @str: The string to be printed
 * Return: Total count of string
 */
int _strprint(char *str)
{
	int i;
	int count = 0;

	if (str)
	{
		for (i = 0; str[i] != '\0'; i++)
		{
			_putchar(str[i]);
			count++;
		}
	}
	return (count);
}
