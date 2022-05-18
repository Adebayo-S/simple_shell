#include "shell.h"

int parse_builtins(char **input, cmd_t *cmd)
{
	int i;

	built_t builtin[] = {
		{"cd", c_dir}, {"env", _env}, {"setenv", _setenv},
		{"unsetenv", _unsetenv}, {"help", _help},
		{NULL, NULL}
	};

	if (!strcmp("exit", input[0]))
		exit_sh(input[0], cmd);

	for (i = 0; builtin[i].f; i++)
	{
		if (!strcmp(builtin[i].name, input[0]))
			builtin[i].f(input);
	}
	exit(EXIT_FAILURE);
}
