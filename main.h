#ifndef MAIN_H
#define MAIN_H

#define BUFFER 1024

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int _printf(const char *format, ...);
void _putchar(char c, int *counter);
int specifiers(const char *input, va_list arguments);
void print_string(va_list arguments, int *counter);
void print_integer(va_list arguments, int *counter);
void print_unsigned_int(va_list arguments, int *counter);

#endif
