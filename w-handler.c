#include "main.h"

/**
*handle_write_char - Prints a string
*@c: char types
*@buffer: buffer array to handle print
*@flages: calculates active flags
*@width: width
*@precision: precision specifier
*@size: size specifier
*Return: number of chars printed
*/
int handle_write_char(char c, char buffer[],
		int flages, int width, int precision, int size)
{
	UNUSED(precision);
	UNUSED(size);

	char padd = ' ';
	int i = 0;

	if (flags & F_SERO)
		padd = '0';
	buffer[i++] = c;
	buffer[i] = '\0';

	int write_count = 1;

	if (width > 1)

		int padding_count = width - 1;
		int buffer_index = BUFF_SIZE - 2;

		for (i = 0; i < padding_count; i++)
			buffer[buffer_index--] = padd;

	if (flags & F_MINUS)

	write_count += write(1, &buffer[0], 1);
	write_count += write(1,
		&buffer[BUFF_SIZE - padding_count - 1], padding_count);

	else

	write_count += write(1,
		&buffer[BUFF_SIZE - padding_count - 1], padding_count);
	write_count += write(1, &buffer[0], 1);


	return (write_count);
}
/**
*write_number - Prints a string
*@buffer: buffer array to handle print
*@flages: calculates active flags
*@width: width
*@precision: precision specifier
*@size: size specifier
*@c: char
*Return: number of chars printed
*/
int handle_write_char(char c, char buffer[],
	int flages, int width, int precision, int size)
{
	char extra_ch = 0;
	char padd = ' ';
	int length = BUFF_size - ind - 1;

	UNUSED(size);

	if (flags & F_ZERO && !(flags & F_MINUS))
		padd = '0';
	if (is_negative)
		extra_ch = '-';
	else if (flags & F_PLUS)
		extra_ch = '+';
	else if (flags & F_SPACE)
		extra_ch = ' ';

	return (write_num(ind, buffer, flags,
		width, precision, length, padd, extra_ch));
}
/**
*write_num - write a number using buffer
*@ind: index on which tjr num starts on the buffer
*@buffer: buffer
*@flags: flags
*@width: width
*@prec: precision specifier
*@length: number length
*@padd: pading char
*@extra_c: extra char
*Return: number of chars printed
*/
int write_num(int ind, char buffer[], int flags,
		int width, int prec, int length, char padd, char extra_c)
{
	int i, padd_start = 1;

	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0' && width == 0)
		return (0);
	if (prec == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		buffer[ind] = padd = ' ';

	if (prec > 0 && prec < length)

		padd = ' ';

	while (prec > length)

		buffer[--ind] = '0';
		length++;

	if (extra_c != 0)
		length++;
	if (width > length)

		for (i = 1; i < width - length + 1; i++)
			buffer[i] = padd;
		buffer[i] = '\0';

		if ((flags & F_MINUS) && padd == ' ')

			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(i, &buffer[ind], length) + write(1, &buffer[1], i - 1));

		else if ((!(flags & F_MINUS) && padd == ' ')

			if (extra_c)
				buffer[--ind] = extra_c;
			return (write(1, &buffer[1], i - 1) + write(1, &buffer[ind], length));

		else if (!(flags & F_MINUS) && padd == '0')
		if (extra_c)
			buffer[--pad_start] = extra_c;
		int write1 = write(1, &buffer[padd_start], i - padd_start);
		int write2 = write(1, &buffer[ind], length - (1 - padd_start));

		return (write1 + write2);

		if (extra_c)
			buffer[--ind] = extra_c;

		return (write(1, &buffer[ind], length));
}
/**
* write_unsgnd - Writes an unsigned number
* @is_negative: Number indicating if the num is negative
* @ind: Index at which the number starts in the buffer
* @buffer: Array of chars
* @flags: Flags specifiers
* @width: Width specifier
* @precision: Precision specifier
* @size: Size specifier
* Return: Number of written chars.
*/
int write_unsgnd(int is_negative, int ind, char buffer[], int flags,
		int width, int precision, int size)
{
	int length = BUFF_SIZE - ind - 1, i = 0;
	char padd = ' ';

	UNUSED(size);
	UNUSED(is_negative);

	if (precision == 0 && ind == BUFF_SIZE - 2 && buffer[ind] == '0')
		return (0);

	if (precision > 0 && precision < length)
		padd = ' ';
	while (precision > length)
		buffer[--ind] = '0';
		 length++;

	if ((flags & F_ZERO) && !(flags & F_MINUS))
		padd = '0';

	if (width > length)

		for (i = 0; i < width - length; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

		if (flags & F_MINUS)


			return (write(1, &buffer[ind], length) + write(1, &buffer[0], i));

		else

			return (write(1, &buffer[0], i) + write(1, &buffer[ind], length));


	return (write(1, &buffer[ind], length));
}
/**
* write_pointer - Write a memory address
* @buffer: Arrays of chars
* @ind: Index at which the number starts in the buffer
* @length: Length of number
* @width: Wwidth specifier
* @flags: Flags specifier
* @padd: Char representing the padding
* @extra_c: Char representing extra char
* @padd_start: Index at which padding should start
* Return: Number of written chars.
*/
int write_pointer(char buffer[], int ind, int length,
	int width, int flags, char padd, char extra_c, int padd_start)
{
	int i;

	if (width > length)

		for (i = 3; i < width - length + 3; i++)
			buffer[i] = padd;

		buffer[i] = '\0';

	if ((flags & F_MINUS) && (padd == ' '))

		buffer[--ind] = 'x';
		buffer[--ind] = '0';

	if (extra_c)
		buffer[--ind] = extra_c;

	int result1 = write(1, &buffer[ind], length);
	int result2 = write(1, &buffer[3], i - 3);

	return (result1 + result2);

	else if (!(flags & F_MINUS) && (padd == ' '))

	buffer[--ind] = 'x';
	buffer[--ind] = '0';

	if (extra_c)
		buffer[--ind] = extra_c;

	int result1 = write(1, &buffer[3], i - 3);
	int result2 = write(1, &buffer[ind], length);

	return (result1 + result2);

	else if (!(flags & F_MINUS) && (padd == ' '))

	if (extra_c)
		buffer[--padd_start] = extra_c;

	buffer[1] = '0';
	buffer[2] = 'x';

	int result1 = write(1, &buffer[padd_start], i - padd_start);
	int result2 = write(1, &buffer[ind], length - (1 - padd_start) - 2);

	return (result1 + result2);

	buffer[--ind] = 'x';
	buffer[--ind] = '0';

	if (extra_c)
		buffer[--ind] = extra_c;

	return (write(1, &buffer[ind], BUFF_SIZE - ind - i));
}
