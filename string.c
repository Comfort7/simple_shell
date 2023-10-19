#include "shell.h"

/**
 * str_length - Returns the length of a string.
 * @string: Pointer to the string.
 * Return: Length of the string.
 */
int str_length(char *string)
{
	int length = 0;

	if (string == NULL)
		return (0);
	while (string[length] != '\0')
	{
		length++;
	}
	return (length);
}

/**
 * str_duplicate - Duplicates a string.
 * @string: String to be duplicated.
 * Return: Pointer to the duplicated string.
 */
char *str_duplicate(char *string)
{
	char *result;
	int length, i;

	if (string == NULL)
		return (NULL);
	length = str_length(string) + 1;
	result = malloc(sizeof(char) * length);
	if (result == NULL)
	{
		errno = ENOMEM;
		perror("Error");
		return (NULL);
	}
	for (i = 0; i < length; i++)
	{
		result[i] = string[i];
	}
	return (result);
}

/**
 * str_compare - Compares two strings.
 * @string1: The shorter string.
 * @string2: The longer string.
 * @num: Number of characters to be compared. 0 if infinite.
 * Return: 1 if the strings are equal, 0 if the strings are different.
 */
int str_compare(char *string1, char *string2, int num)
{
	int iterator;

	if (string1 == NULL && string2 == NULL)
		return (1);
	if (string1 == NULL || string2 == NULL)
		return (0);
	if (num == 0)
	{
		int len1 = str_length(string1);
		int len2 = str_length(string2);

		if (len1 != len2)
			return (0);
		for (iterator = 0; string1[iterator]; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
	else
	{
		for (iterator = 0; iterator < num; iterator++)
		{
			if (string1[iterator] != string2[iterator])
				return (0);
		}
		return (1);
	}
}
