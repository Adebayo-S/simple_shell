#include "shell.h"

/**
 * init_cmd - initialize shell vars
 * @cmd: struct contain shell global vars
 *
 * Return: no return
 */
void init_cmd(cmd_t *cmd)
{
	cmd->mode = 0;
	cmd->args = NULL;
	cmd->ready = 1;
	cmd->status = 0;
}
