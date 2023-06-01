#include "main.h"
#include <unistd.h>
#include <stdarg.h>

int _func(const char *ptr, int l, int *ctr);
/**
 *_printf - function that  produces output according to a format.
 *@format: The format string is composed of zero or more directives.
 *
 *Return:integer(number of characters printed excluding \0)
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0, j;
	char ch;
	char *str;

	va_start(arg, format);
	if (format == NULL)
	{
		count = -1;
	}
	else
	{
		while (*format != '\0')
		{
			if (*format != '%')
			{
				_func(format, 1, &count);
				format++;
			}
			else if (*format == '%' && *(format + 1) == 'c')
			{
				ch = va_arg(arg, int);
				_func(&ch, 1, &count);
				format += 2;
			}
			else if (*format == '%' && *(format + 1) == 's')
			{
				str = va_arg(arg, char *);
				if (str == NULL)
				{
					write(1, "(null)", 6);
					count += 6;
				}
				else
				{
					for (j = 0; str[j] != '\0'; j++)
					{
						_func(str + j, 1, &count);
					}
				}
				format += 2;
			}
			else if (*format == '%' && *(format + 1) == '%')
			{
				_func(format, 1, &count);		
				format += 2;
			}
			else if (*format == '%' && *(format + 1) != '\0')
			{
				_func(format, 1, &count);
				format++;
			}
			else
				return (-1);
		}
	}
	return (count);
}

/**
 * _func- function to print letter
 * @ptr:first param
 * @l:second param
 * @ctr: third param
 * Return:int
 */
int _func(const char *ptr, int l, int *ctr)
{
	write(1, ptr, l);
	*ctr = (*ctr) + l;
	return (*ctr);
}
