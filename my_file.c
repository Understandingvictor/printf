#include "main.h"
/**
 * Descritption : A printf project to build a printf function 
 * 
 * @counter - it provides the number of int or char printed to stdouput
 * @args - this is the variable argument after the const char *format
 * Returns: the number of characters printed
*/

int _printf(const char *format, ...)
{
    int counter = 0;
    va_list arguments;
    va_start(arguments, format);

    while (*format != '\0')
    {
        if (*format == '%')/*This is to handle the format specifiier if % is iterated to.*/
        {
            format++;/*This part of the code will move past the % to the next inline after % sign.*/
            if (*format == 's')
            {
				char *s;
				int sl;

                s = va_arg(arguments, char*);
                sl = strlen(s);
                write(1, s, sl);
                counter = counter + sl;/*This part is to keep a count of the number of bytes written out.*/
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
			else if(*format == 'd' || *format == 'i')
			{
				/**
                 * I still dont know what to do here to make this work
                 * Lemme know of you have aby ideas
                */
				counter++;
			}
        }
        else
        {
            write(1, format, 1);//If there is no format specifier, write format to stdoutput.
            counter++;
        }

        ++format;//This code moves to the next in the format eg. "Hello %s\n".
    }

    va_end(arguments)//This part of the code is intended to free up the memory allocated to arguments.

    return counter;
}

