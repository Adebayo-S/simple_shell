
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
