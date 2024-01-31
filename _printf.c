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
		if (*format == '%')
		{
			format++;
			specifiers(format, arguments);
			counter++;
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

#include "main.h"
/**
 * specifiers - This function is to handle the specifiers
 * for the printf project
 * @input: the format is taken as input and saved in -input-
 * of same data type
 * @arguments: This is the variable list to print out
*/

void specifiers(const char *input, va_list arguments)
{
	if (*input == 'c')
	{
		char c = va_arg(arguments, int);

		write(1, &c, 1);
	}
	else if (*input == 's')
	{
		int stringlength = 0;
		char *string = va_arg(arguments, char *);

		stringlength = strlen(string);
		write(1, string, stringlength);
	}
	else if (*input == '%')
	{
		write(1, input, 1);
	}
	else if (*input == 'd' || *input == 'i')
	{
		char temp_space[256];
		int numbers = va_arg(arguments, int);

		sprintf(temp_space, "%d", numbers);
		write(1, temp_space, strlen(temp_space));
	}
	else if (*input == 'u')
	{
		char temp_space[256];
		unsigned int numbers = va_arg(arguments, unsigned int);

		sprintf(temp_space, "%u", numbers);
		write(1, temp_space, strlen(temp_space));
	}
	else if (*input == 'x')
	{
		char temp_space[256];
		unsigned int num = va_arg(arguments, unsigned int);

		sprintf(temp_space, "%x", num);
		write(1, temp_space, strlen(temp_space));
	}
	else if (*input == 'X')
	{
		char temp_space[256];
		unsigned int num = va_arg(arguments, unsigned int);

		sprintf(temp_space, "%X", num);
		write(1, temp_space, strlen(temp_space));
	}
}
