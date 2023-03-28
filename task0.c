#include <stdarg.h>
#include <unistd.h>
#include <string.h>
#include "main.h"

/**
 * _printf - produces output according to a format
 * @format: character string containing directives
 *
 * Return: number of characters printed
 */
int _printf(const char *format, ...)
{
	int count = 0;
	char c;
	va_list ap;

	va_start(ap, format);

	while (*format)
	{
	if (*format == '%')
	{
	format++;
	switch (*format)
	{
	case 'c':
	c = (char)va_arg(ap, int);
	count += write(1, &c, 1);
	break;

	case 's':
	count += write(1, va_arg(ap, char *), strlen(va_arg(ap, char *)));
	break;

	case '%':
	count += write(1, "%", 1);
	break;
	}
	}

	else
	{
	count += write(1, format, 1);
	}

	format++;
	}

	va_end(ap);

	return (count);
}
