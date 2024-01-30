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
	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			if (*format == 's')
			{
				char *s;

				s = va_arg(arguments, char*);
				write_string(s);
			}
			else if (*format == 'c')
			{
				char c;

				c = va_arg(arguments, int);
				write(1, &c, 1);
				counter++;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				counter++;
			}
		}
		else
		{
			write(1, format, 1);
			counter++;
		}
		++format;
	}
	va_end(arguments);
	return (counter);
}

/**
 * write_string - custom srite funtion to print a string
 * @s: string to be printed out
 * Return: The number of char printed out
*/
int write_string(char *s)
{
	int count;
	char *string = s;
	int string_len;

	count = 0;
	string_len = strlen(string);

	write(1, string, string_len);
	count += string_len;
	return (count);
}
