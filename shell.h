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
#define DELIM " \t\n\r\a"

extern char **environ;

typedef struct cmd_t
{
	int mode;
	char **args;
	int ready;
	// char **_environ;
} cmd_t;

void open_console(void);
void init_cmd(cmd_t *cmd);
void prompt(int status);
void t_error(char *s);
int _fork(void);
char **get_toks(char *args, char *delimiter);
void setcmd(char *buf, cmd_t *cmd);
void runcmd(char* dir, char **input, cmd_t *cmd);
ssize_t getline(char **lineptr, size_t *n, FILE *stream);

/* builtins */
typedef struct builtins
{
	char *name;
	int (*f)(void);
} built_t;

int parse_builtins(char **input);


#endif /* SHELL_H */
