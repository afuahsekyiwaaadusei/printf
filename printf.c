#include "main.h"
#include <unistd.h>

/**
 *_printf - function that  produces output according to a format.
 *@format: The format string is composed of zero or more directives.
 *
 *Return:integer(number of characters printed excluding \0)
 */

int _printf(const char *format, ...)
{
	va_list arg;
	int count = 0, i = 0;

	va_star(arg, format);

	while (*format != '\0')
	{
		if (*format == %)
		{
			while (i <= 6)
			{
				if (*format == 'c')
				{
					write(1, &(va_arg(arg, char)), 1);
					i = 7;
					count++;
					format++;

				}

			}
		}

		write(1, format, 1);
		count++;
		format++;
	}
}
