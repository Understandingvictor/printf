#include "main.h"
/**
  *_printf - acts like printf
  *@format: parameter to be taken
  *Return: an integer
  */
int _printf(const char *format, ...)
{
	va_list args;
	char *str;
	int count = 0;

	while (*format != '\0')
	{
		if (*format == '%')
		{
			format++;
			switch (*format)
			{
				case 's':
					str = va_arg(args, char*);
					count += write_string(str);
					break;
				case 'c':
					_putchar(va_arg(args, int));
					count++;
					break;
				case '%':
					_putchar('%');
					count++;
					break;
				case 'd':
				case 'i':
					count += printInt(va_arg(args, int));
					break;
			}
		}
		else
		{
			_putchar(*format);
			count++;
		}
		format++;
	}
	va_end(args);
	return (count);
}

/**
  *printInt - prints integers and returns number of printed iinteger
  *@num: number to be taken in as parameter
  *Return: returns number of printed integer
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

/**
  *_putchar - prints a character
  *@c: character to be printed
  *Return: returns the character
  */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
  *write_string - function to print a string
  *@s: stringto be printed out
  *Return: The number of char printed out
  */
int write_string(char *s)
{
	int count = 0;

	while (*s != '\0')
	{
		count++;
		s++;
	}
	write(1, s - count, count);
	return (count);
}
