#include "shell.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *buf;
	cmd_t cmd;
	int fd, status;
	size_t buflen = 0;
	pid_t id;
	char **input;

	/*Ensure the 3 file descriptors are open */
	while ((fd = open("/dev/console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}

	init_cmd(&cmd);

	while (cmd.ready)
	{
		status = isatty(STDIN_FILENO);
		prompt(status);
		if (getline(&buf, &buflen, stdin) == EOF)
		{
			cmd.ready = 0;
			exit(EXIT_SUCCESS);
		}

		setcmd(buf, &cmd);
		input = get_toks(buf, " \t\n\r");

		// if (check_builtin())
		// {
		// 	//perform builtin
		// 	continue;
		// }

		/*child process */
		// if (stat(input[0], &st) == 0)
		// {
			if (_fork() == 0)
				runcmd(input, &cmd);
		//}

		else
			wait(NULL);
	}
		free(buf);
		free(input);
		return (0);
}
