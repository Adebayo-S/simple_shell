#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

int main(void)
{
	char *buf;
	int fd, len = 0;
	pid_t id;
	char **input;

	while ((fd = open("console", O_RDWR)) >= 0)
	{
		if (fd >= 3)
		{
			close(fd);
			break;
		}
	}

	while (getline(&buf, &len, stdin) != EOF)
	{
		prompt();
		input = parse_input(buf);

		id = fork();

		/*child process */
		if (id == 0)
		{
			if (execve(input[0], input, NULL) < 0)
			{
				perror("Error: command not found\n");
				exit(EXIT_FAILURE);
			}
		}
		else
			wait(NULL);

		free(buf);
		free(input);
	}
		return (0);
}
