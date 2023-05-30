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

	return (handl_write_char(c, buffer, flags, width, precision, size));
}
/**
*print_char - Prints a charachter
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
	int_length = 0, x;
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
	while (str[lenght] != '\0')
		lenght++;
	if (precision >= 0 && precision < length)
		length = precision;
	if (width > length)
	}
		if (flags & F_MINUS)
	{
		write(1, &str[0], length);
		for (1 = width - length; x > 0. x--)
			write(1, " ", 1);
		return (width);
	}
	else
	{
		for (x = width - length; x > 0; x--)
			write(1, " ", 1);
		write(1, &str[0], length);
		return (width);
	}
	}
	return (write(1, str, length));
}

/**
*print char - Prints a precent sign
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
	UNUSED(types);
	UNUSED(buffer);
	UNUSED(flags);
	UNUSED(width);
	UNUSED(precision);
	UNUSED(size);
	return (write(1, "%%", 1));
}
/**
*print char - Prints int
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
	int x = BUFF_SIZE - 2;
	int is_negative = 0;
	long int n = va_arg(types, long int);
	unsigned long int num;

	n = convert_size_number(n, size);

	if (n == 0)
	buffer[i--] = '0';
	buffer[BUFF_SIZE - 1] = '\0';
	num = (insigned long int)n;

	if (n == 0)
	{
	num = (unsigned log int) ((-1) * n);
	is_negative = 1;
	}
	while (num > 0)
	{
		buffer[i--] = (num % 10) + '0';
		num /= 10;
	}
	i++;
	return (write_number(is_negative, x, buffer, flags, width, precision, size));
}
/**
*print char - Prints an unsigned number
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
		m /= 2;
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