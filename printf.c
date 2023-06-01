#include "main.h"
#include <unistd.h>
#include <stdarg.h>
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
				write(1, format, 1);
				count++;
				format++;
			}
			else if (*format == '%' && *(format + 1) == 'c')
			{
				ch = va_arg(arg, int);
				write(1, &ch, 1);
				count++;
				format += 2;
			}
			else if (*format == '%' && *(format + 1) == 's')
			{
				str = va_arg(arg, char *);
				if (str == NULL)
				{
					write(1,"(null)", 6);
					count += 6;
				}
				else
				{
					for (j = 0; str[j] != '\0'; j++)
					{
						write(1, str + j, 1);
						count++;
					}
				}
				format += 2;
			}
			else if (*format == '%' && *(format + 1) == '%')
			{
				write(1, format, 1);
				count++;
				format += 2;
			}
			else if (*format == '%')
			{
				write(1, format, 1);
				count++;
				format++;
			}
			else
				return (-1);
		}
	}
	return (count);
}
