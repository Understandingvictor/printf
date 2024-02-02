#include "main.h"
/**
 * print_integer - outputs an integer or a variable number
 * of integers to the stdoutput
 * @arguments: the data to convert and print is gotten and
 * saved in it as a parameter
 * @counter: keeps track of the number of printed bytes
 * returns (void);
*/
void print_integer(va_list arguments, int *counter)
{
	int i = 0;
	int n;
	char temp_space[BUFFER];
	int number = va_arg(arguments, int);

	if (number < 0)
	{
		_putchar('-', counter);
		number = -number;
	}
	if (number == 0)
	{
		_putchar('0', counter);
	}
	do {
		temp_space[i++] = (number % 10) + '0';
		number = number / 10;
	} while (number > 0);


	for (n = i - 1; n >= 0; n--)
	{
		_putchar(temp_space[n], counter);
	}
}
