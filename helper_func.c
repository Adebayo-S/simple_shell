#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void prompt(int status)
{
	if (status)
		write(STDIN_FILENO, ":) ", 3);
}

void t_error(char *s)
{
	write(STDERR_FILENO, s, strlen(s));
	exit(EXIT_FAILURE);
}

int _fork(void)
{
	pid_t id = fork();
	if (id < 0)
		t_error("Error: fork failed");
	return (id);
}
