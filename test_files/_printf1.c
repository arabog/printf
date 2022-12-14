#include "main.h"

/**
 * _putchar - prints a character
 * @c: character
 *
 * Return: integer in character form
 */

int _putchar(char c)
{
	return (write(1, &c, 1));
}

/**
 * print_number - prints an integer
 * @n: integer to print
 */

void print_number(int n)
{
	unsigned int n1 = n;

	if (n < 0)
	{
		_putchar('-');
		n1 = -n1;
	}
	if ((n1 / 10) > 0)
		print_number(n1 / 10);
	_putchar((n1 % 10) + '0');
}

/**
 * _printf - prints a formatted string
 * @format: pointer to character string
 *
 * Return: number of characters printed
 */

int _printf(const char *format, ...)
{
	int i = 0, len = 0, flag, j, dec;
	va_list list;
	char *str;
	char ch;

	va_start(list, format);

	if (format)
	{
		while (format[i])
		{
			flag = 1;

			if (format[i] == '%')
			{
				i++;

				switch (format[i])
				{
					case 'c':
						ch = va_arg(list, int);
						write(1, &ch, 1);
						len += 1;
						flag = 0;
						break;
					case 's':
						str = va_arg(list, char *);
						for (j = 0; str[j] != '\0'; j++)
						{
							write(1, &str[j], 1);
							len += 1;
						}
						flag = 0;
						break;
					case 'd':
						dec = va_arg(list, int);
						print_number(dec);
						flag = 0;
						break;
					case 'i':
						dec = va_arg(list, int);
						print_number(dec);
						flag = 0;
						break;
				}
			}
			if (flag)
			{
				write(1, &format[i], 1);
				len += 1;
			}
			i++;
		}
	}
	va_end(list);
	return (len);
}

