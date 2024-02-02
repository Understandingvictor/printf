#include "main.h"

#define buffer 1024
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
			_putchar(*format++);
			counter++;
		}
		else if (*format == '%')
		{
			format++;
			if (*format)
			{
				if (*format == '%')
				{
					_putchar('%');
					counter++;
				}
				else if (*format == 'i' || *format == 's')
					specifiers(format, arguments, &counter);
				else if (*format == 'c' || *format == 'd')
					specifiers(format, arguments, &counter);
				else
				{
					_putchar('%');
					_putchar(*format);
					counter += 2;
				}
			}
			format++;
		}
	}
	va_end(arguments);
	return (counter);
}

/**
 * specifiers - handles the %i %d %c %%
 * @input: saves the data from fornat to handle
 * @counter: keeps track if the bytes printed
 * @arguments: ............../
 * returns: void
*/
void specifiers(const char *input, va_list arguments, int *counter)
{
	if (*input == 's')
	{
		char *string = va_arg(arguments, char *);
		 write(1, string, strlen(string));
		 (*counter) += strlen(string);
	}
	else if (*input == 'c')
	{
		char c = va_arg(arguments, int);

		_putchar(c);
		(*counter)++;
	}
	else if (*input == 'i' || *input == 'd')
	{
		int i = 0;
		int n;
		char temp_space[buffer];
		int number = va_arg(arguments, int);

		if (number < 0)
		{
			_putchar('-');
			number = -number;
		}
		while (number > 0)
		{
			temp_space[i++] = (number % 10) + '0';
			number = number / 10;
		}
		for (n = i - 1; n >= 0; n--)
		{
			_putchar(temp_space[n]);
			(*counter)++;
		}
	}
}
