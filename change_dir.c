#include "shell.h"

/*lsca*/
int c_dir(char **input)
{
	char *args = input[1];
	if (!args || !strcmp(args, "~") || !strcmp(args, "$HOME") || !strcmp(args, "--"))
		cd_home();
	if (!strcmp(args, "-"))
		cd_back();
	if (!strcmp(args, "."))
		cd_curr();
	if (!strcmp(args, ".."))
		cd_parent();
	cd_path();
}

/**
 * cd_back - changes to the previous directory
 *
 * Return: EXIT_SUCCESS
 */
int cd_back(void)
{
	char cwd[PATH_MAX];
	char *p_cwd, *p_oldcwd, *cp_cwd, *cp_oldcwd;

	getcwd(cwd, sizeof(cwd));
	cp_cwd = strdup(cwd);

	p_oldcwd = _getenv("OLDPWD");

	if (p_oldcwd == NULL)
		cp_oldcwd = cp_cwd;
	else
		cp_oldcwd = strdup(p_oldcwd);

	setenv("OLDPWD", cp_cwd);

	if (chdir(cp_oldcwd) == -1)
		setenv("PWD", cp_cwd);
	else
		setenv("PWD", cp_oldcwd);

	p_cwd = _getenv("PWD");

	write(STDOUT_FILENO, p_cwd, _strlen(p_cwd));
	write(STDOUT_FILENO, "\n", 1);

	free(cp_cwd);
	if (p_oldcwd)
		free(cp_oldcwd);

	chdir(p_cwd);
	exit(EXIT_SUCCESS);
}

/**
 * cd_curr - changes to the current directory
 *
 * Return: EXIT_SUCCESS
 */
int cd_curr(void)
{
	char cwd[PATH_MAX];
	char *cp_cwd;

	getcwd(cwd, sizeof(cwd));
	cp_cwd = strdup(cwd);

	setenv("PWD", cp_cwd);
	free(cp_cwd);
	exit(EXIT_SUCCESS);
}

/**
 * cd_parent - changes to the current directory
 *
 * Return: EXIT_SUCCESS
 */
int cd_parent(void)
{
	char cwd[PATH_MAX];
	char *cp_cwd;

	getcwd(cwd, sizeof(cwd));
	cp_cwd = strdup(cwd);

	if (!strcmp("/", cp_cwd))
	{
		free(cp_cwd);
		exit(EXIT_SUCCESS);
	}

	setenv("OLDPWD", cp_cwd);
	free(cp_cwd);
	exit(EXIT_SUCCESS);
}
