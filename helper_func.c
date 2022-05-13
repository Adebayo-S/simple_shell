#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void prompt(void)
{
	fprintf(stdout, ":) ");
}

void t_error(char *s)
{
	fprintf(stdout, "%s\n", s);
	exit(EXIT_FAILURE);
}

int _fork(void)
{
	pid_t id = fork();
	if (id < 0)
		t_error("Error: fork failed\n");
	return (id);
}
