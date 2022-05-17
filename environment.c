#include "shell.h"

char *_getenv(const char *name)
{
	int i;
	char *envar = NULL;

	for (i = 0; environ[i]; i++)
	{
		if (!strcmp(environ[i], name))
		{
			for (i = 0; environ[i] != '='; i++)
				;
			envar = environ[i];
			break;
		}
	}

	return (envar + (i + 1));
}

char *_which(char *input)
{
	char *path;

	path = _getenv("PATH");
}
