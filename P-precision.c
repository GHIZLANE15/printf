#include "main.h"
/**
*get_precision - calculate with precision for printing
*@format: Formatted string
*@i: list of args to print
*@list: list of args
*Return: precision
*/
int get_precision(const char *format, int *i, va_list list)
{
	int curr_i = *i + 1;
	int precision = -1;

	if (format[curr_i] != '.')
		return (precision);
	precision = 0;

	while (format[curr_i] != '\0')
	{
		if (is_digit(format[curr_i]))
		{
			precision *= 10;
			precision += format[curr_i] - '0';
			curr_i++;
		}
		else if (format[curr_i] == '*')
		{
			curr_i++;
			precision = va_arg(list, int);
			break;
		}
		else
		{
			break;
		}
	}
	*i = curr_i - 1;
	return (precision);
}
