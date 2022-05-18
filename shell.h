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
ssize_t getline(char **lineptr, size_t *n, FILE *stream);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char **_strtok(char *line, char *delim);
int _strlen(char *s);
void *_realloc(void *ptr, size_t originalLength, size_t newLength)

#endif // SHELL_H
