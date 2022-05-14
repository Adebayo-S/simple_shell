#include "shell.h"

void runcmd(char **input, cmd_t *cmd)
{
	if (input[0] == NULL)
		exit(EXIT_FAILURE);

	switch (cmd->mode)
	{
		case EXEC:
			if (execve(input[0], input, NULL) < 0)
				t_error("Error: fork failed\n");
			break;
	}

	exit(EXIT_SUCCESS);
}
