#include "main.h"

/**
*print char - Prints a charachter
*@flags: calculates active flags
*@buffer: Buffer to handle
*@width: width
*@precision: Precision specific
*@types: arguments
*@size: specific size
*Return: Number of chars printed
*/
int print_char(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	char c = va_arg(types, int);

	return (handle_write_char(c, buffer, flags, width, precision, size));
}
/**
*print-string - Prints a charachter
*@flags: calculates active flags
*@buffer: Buffer to handle
*@width: width
*@precision: Precision specific
*@types: arguments
*@size: specific size
*Return: Number of chars printed
*/
int print_string(va_list types, char buffer[],
		int flags, int width, int precision, int size)
{
	int length = 0, i;
	char *str = va_arg(types, char *);

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	if (str == NULL)
	{
		str = "(null)";
		if (precision >= 6)
			str = "     ";
	}
	while (str[length] != '\0')
		length++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	{
		if (flags & F_MINUS)
		write(1, &str[0], length);
		for (i = width - length; i > 0; i--)
			write(1, " ", 1);
		return (width);
	}
	else
	{
		for (i = width - length; i > 0; i--)
			write(1, " ", 1);
		write(1, &str[0], length);
		return (width);
	}
	return (write(1, str, length));
}

/**
*print_percent - Prints a percent sign
*@flags: calculates active flags
*@buffer: Buffer to handle
*@width: width
*@precision: Precision specific
*@types: arguments
*@size: specific size
*Return: Number of chars printed
*/
int print_percent(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
*print_int - Prints int
*@flags: calculates active flags
*@buffer: Buffer to handle
*@width: width
*@precision: Precision specific
*@types: arguments
*@size: specific size
*Return: Number of chars printed
*/
int print_int(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{

	int i = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n == 0)
		buffer[i--] = '0';

	buffer[BUFF_SIZE - 1] = '\0';
	num = (unsigned long int)n;

	if (n < 0)

	{
		num = (unsigned long int) ((-1) * n);
		is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, i, buffer, flags, width, precision, size));
}
/**
*print_binary - Prints an unsigned number
*@flags: calculates active flags
*@buffer: Buffer to handle
*@width: width
*@precision: Precision specific
*@types: arguments
*@size: specific size
*Return: Number of chars printed
*/
int print_binary(va_list types, char buffer[],
	int flags, int width, int precision, int size)
{
	unsigned int j, g, x, sum;
	unsigned int a[32];
	int count;

	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);

	j = va_arg(types, unsigned int);
	g = 2147483648;
	a[0] = j / g;
	for (x = 1; x < 32; x++)
	{
		g /= 2;
		a[x] = (j / g) % 2;
	}
	for (x = 0, sum = 0, count = 0; x < 32; x++)
	{
		sum += a[x];
		if (sum || x == 31)
		{
		char y = '0' + a[x];

		write(1, &y, 1);
		count++;
		}
	}
	return (count);
}
