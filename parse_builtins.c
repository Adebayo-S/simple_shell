#include "shell.h"

int parse_builtins(char **input)
{
	int i;

	built_t builtin[] = {
		{"cd", c_dir}, { "env", _env }, { "exit", exit_sh },
		{ "setenv", _setenv }, { "unsetenv", _unsetenv },
		{ "help", _help }, { NULL, NULL }
	};

	for (i = 0; builtin[i].f; i++)
	{
		if (!strcmp(builtin[i].name, input[0]))
		{
			builtin[i].f(input);
			exit(EXIT_SUCCESS);
		}
	}
	exit(EXIT_FAILURE);
}
