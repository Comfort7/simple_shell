#include "shell.h"

/**
 * tokenize - Separates the input line using a specified delimiter.
 * @data: A pointer to the program's data.
 */
void tokenize(data_prog *data)
{
	char *delim = " \t";
	int i, j, counter = 2, length;

	length = str_length(data->input_line);

	if (length && data->input_line[length - 1] == '\n')
		data->input_line[length - 1] = '\0';

	for (i = 0; data->input_line[i]; i++)
	{
		for (j = 0; delim[j]; j++)
		{
			if (data->input_line[i] == delim[j])
				counter++;
		}
	}

	data->tokens = malloc(counter * sizeof(char *));
	if (data->tokens == NULL)
	{
		perror(data->program_name);
		exit(errno);
	}

	i = 0;
	data->tokens[i] = str_duplicate(_strtok(data->input_line, delim));
	data->cmd_name = str_duplicate(data->tokens[0]);
	while (data->tokens[i++])
	{
		data->tokens[i] = str_duplicate(_strtok(NULL, delim));
	}
}
