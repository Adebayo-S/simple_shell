#include "shell.h"

/**
 * _env - prints the evironment variables
 *
 * @input: input data from getline.
 * @cmd: struct of global variables
 * Return: EXIT_SUCCESS on success.
 */
int _env(char **input, cmd_t *cmd)
{
	char **tmp = input;
	tmp = NULL;

	int i, j;

	for (i = 0; environ[i]; i++)
	{
		for (j = 0; environ[i][j]; j++)
			;

		write(STDOUT_FILENO, environ[i], j);
		write(STDOUT_FILENO, "\n", 1);
	}
	cmd->status = 0;
	exit(EXIT_SUCCESS);
}

char *_getenv(const char *name)
{
	int i, j;
	char *envar = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (!strcmp(environ[i], name))
		{
			for (j = 0; environ[i][j] != '='; j++)
				;
			envar = environ[i];
			break;
		}
	}

	return (envar + (i + 1));
}

char *_which(char *input)
{
	char *path, *cpy_path, *path_toks, *dir;
	int len_dir, len_input, i;

	path = _getenv("PATH");
	if (path)
	{
		cpy_path = strdup(path);
		len_input = strlen(input);
		path_toks = strtok(cpy_path, ":");
		i = 0;
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
