# simple_shell
🤖 Simple command line interpreter by @Adebayo-S and @moscode

<img style="width: 600px" src="https://s3.amazonaws.com/intranet-projects-files/holbertonschool-low_level_programming/235/shell.jpeg">

/**
 * c_dir - change directory master function
 * @input: the input string
 */
/*
 * int c_dir(char **input)
 * {
 * char *args = input[1];
 * if (!args || !_strcmp(args, "~") || !_strcmp(args, "$HOME") ||
 * !_strcmp(args, "--"))
 * return (cd_home());
 * else if (!_strcmp(args, "-"))
 * return (cd_back());
 * lse if (!_strcmp(args, "."))
 * return (cd_curr());
 * else if (!_strcmp(args, ".."))
 * return (cd_parent());
 * else
 * return (cd_path(input[1]));
 * }
 */
