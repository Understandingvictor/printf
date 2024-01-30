#include "main.h"
/**
 * _printf - A self implemented printf project
 * @format: format string that may or may not contain
 * the format specifiers
 * Return: number of printed bytes
*/

int _printf(const char *format, ...)
{
	int counter = 0, num;
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
			else if (*format == 'i' || *format == 'd')
			{
				num = va_arg(arguments, int);
				counter += printInt(num);
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

/**
  *printInt - prints integers and returns number of printed integer
  *@num: number to be taken in as parameter
  *Return: it returns number of printed integer.
  */
int printInt(int num)
{
	int reversed = 0;
	int count = 0;

	if (num < 0)
	{
		_putchar('-');
		count++;
		num = -num;
	}

	if (num == 0)
	{
		_putchar('0');
		count++;
		return (count);
	}

	while (num != 0)
	{
		reversed = num % 10;
		reversed += reversed * 10;
		num /= 10;
	}

	while (reversed != 0)
	{
		_putchar(reversed % 10 + '0');
		reversed /= 10;
		count++;
	}
	_putchar('\n');
	return (count);
}
