#include "shell.h"

/**
 * execute - Executes a command with its entire path variables.
 * @data: A pointer to the program's data.
 * Return: On success, returns 0; otherwise, returns -1.
 */
int execute(data_prog *data)
{
	int result = 0, status;
	pid_t child_pid;

	result = builtins_list(data);
	if (result != -1)
	{
		return result;
	}

	result = find_program(data);
	if (result != 0)
	{
		return result;
	}
	else
	{
		child_pid = fork();
		if (child_pid == -1)
		{
			perror(data->cmd_name);
			exit(EXIT_FAILURE);
		}
	if (child_pid == 0)
	{
		result = execve(data->tokens[0], data->tokens, data->env);
		if (result == -1)
		{
			perror(data->cmd_name);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(&status);
		if (WIFEXITED(status))
		{
			errno = WEXITSTATUS(status);
		}
		else if (WIFSIGNALED(status))
		{
			errno = 128 + WTERMSIG(status);
		}
	}
	}
	return (0);
}
