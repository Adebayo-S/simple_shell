#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/wait.h>

typedef struct cmd_t
{
	int *mode;
	char **args;
} cmd_t;

void prompt(void);
char **parse_input(char *args);
void setcmd(char *buf, cmd_t *cmd);
void runcmd(char **input, cmd_t *cmd);

#endif // SHELL_H
