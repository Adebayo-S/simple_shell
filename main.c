#include "shell.h"

int main(int ac __attribute__((unused)), char **av __attribute__((unused)))
{
	char *buf;
	cmd_t cmd;
	int fd;
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

	while (1)
	{
		int status = isatty(STDIN_FILENO);
		prompt(status);
		getline(&buf, &buflen, stdin);

		setcmd(buf, &cmd);
		input = get_toks(buf, " \t\n\r");

		// if (check_builtin())
		// {
		// 	//perform builtin
		// 	continue;
		// }

		/*child process */
		if (_fork() == 0)
			runcmd(input, &cmd);
		else
			wait(NULL);
	}
		free(buf)
		free(input);
		return (0);
}
