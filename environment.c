#include "shell.h"

/**
 * _env - prints the evironment variables
 *
 * @input: input data from getline.
 * @cmd: struct of global variables
 * Return: EXIT_SUCCESS on success.
 */
int _env(char **input)
{
	char **tmp = input;

	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			tmp++; /* dud */

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	return (1);
}

/**
 * _getenv - gets an environment variable
 *
 * @name: name of environmental variable
 *
 * Return: pointer to the value in the environment,
 * or NULL if there is no match *
 */
char *_getenv(const char *name)
{
	int i, j, start;
	char *envar = NULL;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j] != '='; j++)
		{
			if (environ[i][j] != name[j])
			{
				start = 0;
				break;
			}
			envar = environ[i];
		}
		if (environ[i][j] == '=')
		{
			start = (j + 1);
			break;
		}
	}
	return (envar + start);
}

/**
 * _which - Append command to corresponding PATH directory
 * @input: input data from getline.
 *
 * Return: the path of the command or NULL if invalid
 */
char *_which(char *input)
{
	char *path, *cpy_path, *path_toks, *dir;
	int len_dir, len_input;
	struct stat st;

	path = _getenv("PATH");

	if (path)
	{
		cpy_path = strdup(path);
		len_input = strlen(input);
		path_toks = strtok(cpy_path, ":");

		while (path_toks != NULL)
		{
			len_dir = strlen(path_toks);
			dir = malloc(len_dir + len_input + 2);
			strcpy(dir, path_toks);
			strcat(dir, "/");
			strcat(dir, input);
			strcat(dir, "\0");
			if (stat(dir, &st) == 0)
			{
				free(cpy_path);
				return (dir);
			}
			free(dir);
			path_toks = strtok(NULL, ":");
		}
		free(cpy_path);
		if (stat(input, &st) == 0)
			return (input);
		return (NULL);
	}
	if (input[0] == '/')
		if (stat(input, &st) == 0)
			return (input);
	return (NULL);
}
