#include "shell.h"

/**
 * main - Entry point of the shell
 *
 * @ac: Argument count
 * @av: Argument vector
 *
 * Return: the (int)value of status.
 */
int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *buf = NULL, *dir = NULL, *c_input = NULL;
	cmd_t cmd;
	ssize_t status = 0, line = 0;
	size_t buflen = 0;
	char **input = NULL;

	signal(SIGINT, handl_sigint);
	open_console();
	init_cmd(&cmd);

	while (cmd.ready)
	{
		status = isatty(STDIN_FILENO);
		prompt(status);

		line = getline(&buf, &buflen, stdin);

		if (line <= EOF)
			cmd.ready = 0, exit(EXIT_SUCCESS);

		setcmd(buf, &cmd);
		c_input = handl_comment(buf);
		if (c_input == NULL)
			continue;

		input = get_toks(c_input, DELIM);

		if (parse_builtins(input, &cmd))
		{
			free(input);
			continue;
		}

		dir = _which(input[0]);

		if (dir && _fork() == 0)
			runcmd(dir, input, &cmd);
		else if (!dir)
			t_error("invalid command\n");
		else
			wait(NULL);
		free(input), free(dir), free(c_input), free(buf);
	}
	free(input), free(buf);
	return (cmd.status);
}
