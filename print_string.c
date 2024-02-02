#include "main.h"
/**
 * print_string - a function that prints a string and also accounts for
 * When the string is null
 * @arguments: data string to print
 * @counter: to keep track of the printed bytes
 * return (void)
*/

void print_string(va_list arguments, int *counter)
{
	char *string = va_arg(arguments, char *);

	if (string == NULL)
	{
		string = "(null)";
	}

	size_t length = strlen(string);

	write(1, string, length);
	(*counter) += length;
}
