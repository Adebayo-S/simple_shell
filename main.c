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
	char *buf = NULL, *dir = NULL;
	cmd_t cmd;
	ssize_t status = 0, line = 0;
	size_t buflen = 0;
	char **input = NULL;

	/*Ensure the 3 file descriptors are open */
	open_console();

	/*Initialize the global cmd struct variable*/
	init_cmd(&cmd);

	/*REPL Loop*/
	while (cmd.ready)
	{
		status = isatty(STDIN_FILENO);
		prompt(status);

		line = _getline(&buf, &buflen, stdin);

		if (line <= EOF)
			cmd.ready = 0, exit(EXIT_SUCCESS);

		setcmd(buf, &cmd);
		input = get_toks(buf, DELIM);

		if (input[0] == NULL)
			continue;

		/*if (parse_builtins(input, &cmd))*/
			/*continue;*/

		dir = _which(input[0]);

		if (dir && _fork() == 0)
			runcmd(dir, input, &cmd);
		else if (!dir)
			t_error("invalid command\n");
		else
			wait(NULL);
		free(input), free(dir);
	}
	free(input); free(buf);
	return (cmd.status);
}
