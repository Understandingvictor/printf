#include "main.h"
/**
 * specifiers - handles the %i %d %c %%
 * @input: saves the data from fornat to handle
 * @arguments: ............../
 * Return: counter
*/
int specifiers(const char *input, va_list arguments)
{
	int counter = 0;

	if (*input == 's')
		print_string(arguments, &counter);
	else if (*input == 'c')
	{
		char c = va_arg(arguments, int);

		_putchar(c, &counter);
	}
	else if (*input == 'i' || *input == 'd')
		print_integer(arguments, &counter);
	else if (*input == 'u')
		print_unsigned_int(arguments, &counter);
	else
		_putchar(*input, &counter);
	return (counter);
}
