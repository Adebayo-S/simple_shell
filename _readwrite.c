#include "shell.h"

/**
 * _readwrite - reads the input string.
 *
 * @is_eof: return value of getline function
 * @status: determines if the shell is interactive
 * Return: the input string.
 */
char *_readwrite(int status, ssize_t *is_eof)
{
	char *buffer = NULL;
	size_t bufsize = 0;

	prompt(status);
	*is_eof = _getline(&buffer, &bufsize, stdin);

	return (buffer);
}
