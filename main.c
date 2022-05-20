#include "shell.h"

/**
 * main - Entry point of the shell
 *
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: the (int)value of status.
 */
int main(int ac __attribute__((unused)), char **av)
{
	cmd_t cmd;

	signal(SIGINT, handl_sigint);
	/*open_console();*/
	init_cmd(&cmd, av);
	rep_loop(&cmd);
	free_cmd(&cmd);
	return (cmd.status);
}

/**
 * rep_loop - read-eval-print loop of shell
 * @cmd: data relevant (av, input, args)
 *
 * Return: no return.
 */
void rep_loop(cmd_t *cmd)
{
	char *c_input = NULL;
	ssize_t /*state = 0,*/ eof_c = 0;

	while (cmd->ready)
	{
		/*state = isatty(STDIN_FILENO);*/
		c_input = _readwrite(1, &eof_c);

		if (eof_c <= EOF)
			cmd->ready = 0, free(c_input);
		else
		{
			c_input = handl_comment(c_input);
			if (c_input == NULL || c_input[0] == '\n')
				continue;

			c_input = parse_input(c_input, cmd);
			(cmd->ready) = apply_seperators(cmd, c_input);
			free(c_input);
		}
	}
}

