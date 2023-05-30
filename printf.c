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
	int count = 0, i = 0, j;
	char ch;
	char *str;

	va_start(arg, format);
	while (*format != '\0')
	{
		if (*format == '%')
		{
			i = 1;
			while (i <= 7)
			{
				if (format[i] == 'c')
				{
					ch = va_arg(arg, int);
					write(1, &ch, 1);
					i = 7;
					count++;
					format += 2;
				}
				if (format[i] == 's')
				{
					str = va_arg(arg, char *);
					for (j = 0; str[j] != '\0'; j++)
					{
						write(1, str + j, 1);
						count += j;
					}
					format += 2;
				}
				if (format[i] == '%')
				{
					write(1, format + i, 1);
					i = 7;
					count++;
					format += 2;
				}
				i++;
			}
		}
		write(1, format, 1);
		count++;
		format++;
	}
	return (count);
}
