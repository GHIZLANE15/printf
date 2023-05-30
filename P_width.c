#include "main.h"

/**
*get_width - ccalculates the width for printing
*@format: Formated string in which to print the arguments.
*@i: list of args to printed
*@list: list of args to printed
*Return: width
*/
int get_width(const char *format, int *i, va_list list)
{
	int curr_i = *i + i;
	int width = 0;

	while (format[curr_i] != '\0')
	{
		if (is_digit(format[curr_i]))
		{
		width *= 10;
		width += format[curr_i] - '0';
			curr_i++;
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			width = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = curr_i - 1;
	return (width);
}
