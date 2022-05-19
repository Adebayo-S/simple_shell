#include "shell.h"

/**
 * free_grid - frees a 2 dimensional grid.
 * @grid: multidimensional array of integers.
 * @height: height of the grid.
 *
 * Return: no return
 */
void free_grid(char **grid, int height)
{
	height -= 1;

	if (grid != NULL && height != 0)
	{
		for (; height >= 0; height--)
		{
			printf("%d\n", height);
			printf("%s\n", grid[height]);
			free(grid[height]);
			printf("inner grid freed\n");
		}
		free(grid);
		printf("grid freed\n");
	}
}
