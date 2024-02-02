#include "main.h"
/**
 * _printf - A self implemented printf project
 * @format: format string that may or may not contain
 * the format specifiers
 * Return: number of printed bytes
*/
int _printf(const char *format, ...)
{
	int counter = 0;
	va_list arguments;

	va_start(arguments, format);
	while (*format)
	{
		if (*format != '%')
		{
			_putchar(*format++, &counter);
		}
		else if (*format == '%')
		{
			format++;
			if (*format)
			{
				if (*format == '%')
				{
					_putchar('%', &counter);
				}
				else
				{
					counter += specifiers(format, arguments);
				}
			}
			format++;
		}
	}
	va_end(arguments);
	return (counter);
}
