#include "shell.h"

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
			cmd->status = 2;
		}
		cmd->status = (ustatus % 256);
		cmd->ready = 0;
	}
	cmd->ready = 0;
	return (1);
}

/**
 * c_dir - change directory master function
 * @input: the input string
 */
/*
 * int c_dir(char **input)
 * {
 * char *args = input[1];
 * if (!args || !_strcmp(args, "~") || !_strcmp(args, "$HOME") ||
 * !_strcmp(args, "--"))
 * return (cd_home());
 * else if (!_strcmp(args, "-"))
 * return (cd_back());
 * lse if (!_strcmp(args, "."))
 * return (cd_curr());
 * else if (!_strcmp(args, ".."))
 * return (cd_parent());
 * else
 * return (cd_path(input[1]));
 * }
 */
