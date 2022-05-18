#include "shell.h"

/**
 * parse_builtins - checks for builtins and executes them
 *
 * @input: the input string
 * @cmd: the command struct
 * Return: 1 on success and 0 on failure
 */
int parse_builtins(char **input, cmd_t *cmd)
{
	int i;

	built_t builtin[] = {
		{"cd", c_dir}, {"env", _env}, /*{"setenv", _setenv},
		{"unsetenv", _unsetenv}, {"help", _help},*/
		{NULL, NULL}
	};

	if (!strcmp("exit", input[0]))
		return (exit_sh(input, cmd));

	for (i = 0; builtin[i].name; i++)
	{
		if (!strcmp(builtin[i].name, input[0]))
			return (builtin[i].f(input));
	}
	return(0);
}
