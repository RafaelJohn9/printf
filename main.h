#ifndef MAIN_H
#define MAIN_H

/*HEADERS*/
#include <stdarg.h>
#include <stdlib.h>
#include <stdint.h>
#include <string.h>
#include <stddef.h>
#include <unistd.h>
#include <limits.h>

/*FUNCTION PROTOTYPES*/
int _printf(const char *format, ...);
int _putchar(char c);
int string(va_list list);
int _strprint(char *str);
int _print_int(const char *str, ...);
int (*get_function(char chr))(va_list);
/*int _print_int(int holder);*/

/*HELPER FUNCTIONS*/
int print_percent(va_list list);
int printint(va_list list);
int printstr(va_list list);
int printchar(va_list list);
int _strlen(const char *str);

/* STRUCTS*/

/**
 * struct specifiers_t - struct for _printf spec. characters
 *
 * @spec: specifier characters
 * @print_val: function pointer to print function corresponding to spec.
 */

typedef struct specifiers_t
{
	char spec;
	int (*print_val)(va_list);

} specifiers_t;


#endif
