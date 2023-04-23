#include <unistd.h>

/**
 * _putchar-print out one char
 * @c:value
 * Return: char as int
 */
int _putchar(char c)
{
	return (write(1, &c, 1));
}
