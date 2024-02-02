#include "main.h"
/**
 * _putchar - writes a char to the std output
 * @c: char to print out
 * @counter: keeps track of the bytes printed
 * Return: void
*/
void _putchar(char c, int *counter)
{
	if (c == '\n')
		write(1, "\n", 1);
	else
		write(1, &c, 1);
	(*counter)++;
}
