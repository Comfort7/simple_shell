#include "shell.h"

/**
 * long_to_string - Converts a number to a string in the specified base.
 * @num: The number to be converted to a string.
 * @string: The buffer to save the number as a string.
 * @base: The base for converting the number.
 */
void long_to_string(long num, char *string, int base)
{
	int index = 0, inNegative = 0;
	long quotient = num;
	char letters[] = "0123456789abcdef";

	if (quotient == 0)
		string[index++] = '0';
	if (string[0] == '-')
		inNegative = 1;
	while (quotient)
	{
		if (quotient < 0)
		string[index++] = letters[-(quotient % base)];
		quotient /= base;
	}
	if (inNegative)
		string[index++] = '-';
	string[index] = '\0';
}

/**
 * _atoi - Converts a string to an integer.
 * @s: Pointer to the string to be converted.
 * Return: The integer representation of the string, or 0 if not a
 * valid integer.
 */
int _atoi(char *s)
{
	int sign = 1;
	unsigned int num = 0;

	while (*s && (*s == ' ' || *s == '\t' || *s == '\n' || *s == '\r'))
	{
		s++;
	}

	if (*s == '-')
	{
		sign = -1;
		s++;
	}
	else if (*s == '+')
	{
		s++;
	}

	while (*s >= '0' && *s <= '9')
	{
		num = (num * 10) + (*s - '0');
		s++;
	}

	return (num * sign);
}

/**
 * count_characters - Counts the occurrences of a character in a string.
 * @string: Pointer to the string.
 * @character: The character to be counted.
 * Return: The count of character occurrences in the string.
 */
int count_characters(char *string, char *character)
{
	int i = 0, counter = 0;

	for (; string[i]; i++)
	{
		if (string[i] == character[0])
			counter++;
	}
	return (counter);
}
