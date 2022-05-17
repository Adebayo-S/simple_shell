#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>

#define EXEC 1
#define MAXARGS 10

typedef struct cmd_t
{
	int mode;
	char **args;
	int ready;
} cmd_t;

void init_cmd(cmd_t *cmd);
void prompt(int status);
void t_error(char *s);
int _fork(void);
char **get_toks(char *args, char *delimiter);
void setcmd(char *buf, cmd_t *cmd);
void runcmd(char **input, cmd_t *cmd);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);


#endif // SHELL_H
