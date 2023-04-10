#include "main.h"

/**
 * _power - calculate the result of raising base to the power of pow
 * @base: the base of the exponent
 * @pow: the power of the exponent
 * Return: the result of base raised to the power of pow
 */
unsigned long int _power(unsigned int base, unsigned int pow)
{
	unsigned long int result = 1;
	unsigned int i;

	for (i = 0; i < pow; i++)
	{
		result *= base;
	}
	return (result);
}

/**
 * print_binary - prints the binary representation of a number
 * @n: the number to be printed in binary
 * Return: void
 */
void print_binary(unsigned long int n)
{
	unsigned long int mask = _power(2, sizeof(unsigned long int) * 8 - 1);
	char flag = 0;

	while (mask > 0)
	{
		/* Check if the current bit is set */
		if ((n & mask) == mask)
		{
			/* If it is set, print a '1' and set the flag */
			_putchar('1');
			flag = 1;
		}
		else if (flag == 1 || mask == 1)
		{
			/* If the flag is set or we've reached the last bit, print a '0' */
			_putchar('0');
		}

		/* Shift the mask one bit to the right */
		mask >>= 1;
	}
}
