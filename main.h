#ifndef MAIN_H
#define MAIN_H

#include <unistd.h>
#include <stdarg.h>
#include <string.h>
#include <stdio.h>

int _printf(const char *format, ...);
void specifiers(const char *input, va_list arguments, int *counter);
void _putchar(char c);
void specifiers_1(const char *input, int *counter);

#endif
