#include "shell.h"

/**
 * _strtok - separates strings with delimiters
 * @line: pointer to the array received in getline
 * @delim: characters marking off string parts
 * Return: a pointer to the created token
 */
char *_strtok(char *line, const char *delim)
{
	static char *str;
	char *cpstr;

	if (line != NULL)
		str = line;
	if (str == NULL || *str == '\0')
		return (NULL);

	while (*str != '\0' && strchr(delim, *str) != NULL)
	{
		str++;
	}

	cpstr = str;

	while (*str != '\0' && strchr(delim, *str) == NULL)
	{
		str++;
	}

	if (*str != '\0')
	{
		*str = '\0';
		str++;
	}

	return (cpstr);
}
