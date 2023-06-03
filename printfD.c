#include "main.h"
#include <stdio.h>
/**
 *get_length - gets the length of intger passed to it.
 *@num: intger.
 *
 *Return: the length of integer.
 */
int get_length(long int num)
{
	int i = 0;

	if (num == 0)
	{
		i++;
	}
	else
	{
		if (num < 0)
		{
			i++;
			num = -num;
		}
		while (num > 0)
		{
			num /= 10;
			i++;
		}
	}
	i++;
	return (i);
}


/**
 *intToString - converts an intger to a string.
 *@num: integer
 *@buf: buffer to hold  the converted string.
 *
 *Return: 0 if successful
 */

int intToString(long int num, char *buf)
{
	int i = 0, start, end;
	char tmp;

	if (num == 0)
	{
		buf[i++] = '0';
	}
	else
	{
		if (num < 0)
		{
			buf[i++] = '-';
			num = -(num);
		}
		start = i;

		while (num > 0)
		{
			buf[i++] = '0' + (num % 10);
			num /= 10;
		}
		end = i - 1;
		while (start < end)
		{
			tmp = buf[start];
			buf[start] = buf[end];
			buf[end] = tmp;
			start++;
			end--;
		}
	}
	buf[i] = '\0';
	return (i);
}




