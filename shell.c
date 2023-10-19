#include "shell.h"

/**
 * main - Initialize the variables of the program.
 * @argc: Number of values received from the command line.
 * @argv: Number of values received from the program's execution.
 * @env: Environ passed to the program's execution.
 * Return: 0 on success.
 */
int main(int argc, char *argv[], char *env[])
{
	data_prog data_struct = {NULL}, *data = &data_struct;
	char *prompt = "$ ";

	initialize_data(data, argc, argv, env);
	signal(SIGINT, handle_ctrl_c);

	if (isatty(STDIN_FILENO) && isatty(STDOUT_FILENO) && argc == 1)
	{
		_print_error(2, data);
		prompt = PROMPT_MSG;
	}
	sisifo(prompt, data);
	return (0);
}

/**
 * handle_ctrl_c - Prints the prompt in a new line when the
 * signal SIGINT(ctrl + c) is sent to the program.
 * @opr UNUSED: Unused option in the prototype.
 */
void handle_ctrl_c(int opr UNUSED)
{
	_print("\n");
	_print(PROMPT_MSG);
}

/**
 * initialize_data - Initialize the struct with the info of the program.
 * @data: Pointer to the struct of data.
 * @argc: Number of values received from the command line.
 * @argv: Array of arguments passed to the program execution.
 * @env: Environ passed to the program execution.
 */
void initialize_data(data_prog *data, int argc, char *argv[], char **env)
{
	int i = 0;

	data->program_name = argv[0];
	data->input_line = NULL;
	data->cmd_name = NULL;
	data->exec_counter = 0;

	if (argc == 1)
	{
		data->file_descriptor = STDIN_FILENO;
	}
	else
	{
		data->file_descriptor = open(argv[1], O_RDONLY);
		if (data->file_descriptor == -1)
		{
			_print(data->program_name);
			_print(": 0: Can't open ");
			_print(argv[1]);
			_print("\n");
			exit(126);
		}
	}
	data->tokens = NULL;

	data->env = malloc(sizeof(char *) * 50);
	if (env)
	{
		for (i = 0; env[i]; i++)
		{
			data->env[i] = str_duplicate(env[i]);
		}
	}
	data->env[i] = NULL;

	data->alias_list = malloc(sizeof(char *) * 20);
	for (i = 0; i < 20; i++)
	{
		data->alias_list[i] = NULL;
	}
}

/**
 * sisifo - An infinite loop that shows the prompt.
 * @prompt: Prompt to be printed.
 * @data: Data related to the program.
 */
void sisifo(char *prompt, data_prog *data)
{
	int error_code = 0, string_len = 0;

	while (++(data->exec_counter))
	{
		_print(prompt);
		error_code = string_len = _getline(data);

		if (error_code == EOF)
		{
			exit(errno);
		}
		if (string_len >= 1)
		{
			expand_alias(data);
			expand_variables(data);
			tokenize(data);

		if (data->tokens[0])
		{
			error_code = execute(data);

		if (error_code != 0)
			_print_error(error_code, data);
		}
		free_recurrent_data(data);
		}
	}
}
