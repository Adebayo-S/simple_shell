#include <stdio.h>
#include "shell.h"

char **get_toks(char *args, char *delimiter)
{
	int i = 0;
	char *token;
	char **output = malloc(MAXARGS * sizeof(char *));
	if (output == NULL)
		return (NULL);

	token = strtok(args, delimiter);
	while (token != NULL)
	{
		output[i] = token;
		i++;
		if (i > MAXARGS)
			output = realloc(output, (i) * sizeof(char *));
		token = strtok(NULL, delimiter);
	}
	output[i] = NULL;

	return (output);
}
