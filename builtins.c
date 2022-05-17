#include "shell.h"

/**
 * _env - prints the evironment variables
 *
 * @input: input data from getline.
 * Return: EXIT_SUCCESS on success.
 */
int _env(char **input)
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

	exit(EXIT_SUCCESS);
}
