#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "shell.h"

void prompt(int status)
{
	if (status)
		fprintf(stderr, ":) ");
}

void t_error(char *s)
{
	fprintf(stderr, "%s", s);
	exit(EXIT_FAILURE);
}

int _fork(void)
{
	pid_t id = fork();
	if (id < 0)
		t_error("Error: fork failed\n");
	return (id);
}
