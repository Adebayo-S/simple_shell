#include "shell.h"

/**
 * _setenv - create or modify existing environmental variable in linked list
 * @env: linked list
 * @str: user's typed in command (e.g. "setenv USER Superman")
 * Return: 0 on success, 1 on fail
 */
int _setenv(list_t **env, char **str)
{
	int index = 0, j = 0;
	char *cat;
	list_t *holder;

	if (str[1] == NULL || str[2] == NULL)
	{
		write(STDOUT_FILENO, "Too few arguments\n", 18);
		free_double_ptr(str);
		return (-1);
	}
	cat = _strdup(str[1]); /* concatenate strings to be new node data */
	cat = _strcat(cat, "=");
	cat = _strcat(cat, str[2]);
	index = find_env(*env, str[1]); /* find idx to traverse to node */
	if (index == -1)
	{
		add_end_node(env, cat); /* doesn't exist? create env var */
	}
	else
	{
		holder = *env;
		while (j < index)
		{
			holder = holder->next;
			j++;
		}
		free(holder->var); /* else free malloced data */
		holder->var = _strdup(cat); /* assign to new malloced data */
	}
	free(cat);
	free_double_ptr(str);
	return (0);
}