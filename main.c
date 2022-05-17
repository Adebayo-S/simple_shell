#include "shell.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *buf, *dir;
	struct stat st;
	cmd_t cmd;
	int fd, status;
	size_t buflen = 0;
	pid_t id;
	char **input;

	/*Ensure the 3 file descriptors are open */
	open_console();

	/*Initialize the global cmd struct variable*/
	init_cmd(&cmd);

	/*REPL Loop*/
	while (cmd.ready)
	{
		status = isatty(STDIN_FILENO);
		prompt(status);

		if (getline(&buf, &buflen, stdin) <= EOF)
			cmd.ready = 0, exit(EXIT_SUCCESS);

		setcmd(buf, &cmd);
		input = get_toks(buf, DELIM);

		dir = _which(input[0]);

		if (parse_builtins(dir))
			continue;

		if (dir && _fork() == 0)
			runcmd(dir, input, &cmd);
		else
			wait(NULL);
	}

	free(buf);
	free(input);
	return (0);
}
