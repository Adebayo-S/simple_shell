#include <stdio.h>
#include "shell.h"

char **parse_input(char *args)
{
	char *delimiter = " ";
	char **output = malloc((_strlen(args) + 1) * sizeof(char *));
	if (output == NULL)
		return (NULL);

	char* token = _strtok(args, delimiter);
	int i = 0;

	while (token != NULL)
	{
		output[i] = token;
		i++;
		token = strtok(NULL, delimiter);
	}
	output[i] = NULL;

	return (output);
}
