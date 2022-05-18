#include "shell.h"

/**
 * _env - prints the evironment variables
 *
 * @input: input data from getline.
 * @cmd: struct of global variables
 * Return: EXIT_SUCCESS on success.
 */
int _env(char **input, cmd_t *cmd)
{
	char **tmp = input;
	tmp = NULL;

	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}

	exit(EXIT_SUCCESS);
}

/**
 * exit_sh - exits the shell
 *
 * @input: vector of inputed arguments
 * @cmd: struct of global variables
 * Return: 0 on success.
 */
int exit_sh(char **input, cmd_t *cmd)
{
	unsigned int ustatus;
	int is_digit;
	int str_len;
	int big_number;

	if (input[1])
	{
		ustatus = _atoi(input[1]);
		is_digit = _isdigit(input[1]);
		str_len = _strlen(input[1]);
		big_number = ustatus > (unsigned int)INT_MAX;
		if (!is_digit || str_len > 10 || big_number)
		{
			t_error("Invalid exit status");
			cmd->ready = 0;
			cmd->status = 2;
		}
		cmd->status = (ustatus % 256);
	}
	exit(EXIT_SUCCESS);
}
