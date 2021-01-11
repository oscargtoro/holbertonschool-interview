#include "sandpiles.h"

/**
 * print_grid - prints grid in easy to see format
 * @grid: grid to print
 */
static void print_grid(int grid[3][3])
{
	int i, j;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (j)
				printf(" ");
			printf("%d", grid[i][j]);
		}
		printf("\n");
	}
}

/**
 * topple - toples one space in a grid
 * @grid: a 3x3 grid
 * @i: row to topple
 * @j: column to topple
 */
void topple(int grid[3][3], int i, int j)
{
	grid[i][j] = grid[i][j] - 4;
	if (j + 1 < 3)
		grid[i][j + 1] = grid[i][j + 1] + 1;
	if (j - 1 >= 0)
		grid[i][j - 1] = grid[i][j - 1] + 1;
	if (i + 1 < 3)
		grid[i + 1][j] = grid[i + 1][j] + 1;
	if (i - 1 >= 0)
		grid[i - 1][j] = grid[i - 1][j] + 1;
}

/**
 * check_stable - checks if the sandpile is stable, if not calls topple.
 * @grid: 3x3 grid to check
 * @list: 3x3 grid with the spaces that need toppling
 */
void check_stable(int grid[3][3], int list[3][3])
{
	int i, j = 0;
	int stable = 0;

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (list[i][j] == 1)
			{
				list[i][j] = 0;
				topple(grid, i, j);
			}
		}
	}

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			if (grid[i][j] > 3)
			{
				list[i][j] = 1;
				stable = 1;
			}
		}
	}

	if (stable == 0)
		return;
	printf("=\n");
	print_grid(grid);
	check_stable(grid, list);
}

/**
 * sandpiles_sum - Computes the sum of two sandpiles.
 *
 * @grid1: 3x3 stable sandpile.
 * @grid2: 3x3 stable sandpile.
 */
void sandpiles_sum(int grid1[3][3], int grid2[3][3])
{
	int i, j = 0;
	int list[3][3] = {
		{0, 0, 0},
		{0, 0, 0},
		{0, 0, 0}
	};

	for (i = 0; i < 3; i++)
	{
		for (j = 0; j < 3; j++)
		{
			grid1[i][j] = grid1[i][j] + grid2[i][j];
			if (grid1[i][j] > 3)
				list[i][j] = 1;
		}
	}

	printf("=\n");
	print_grid(grid1);
	check_stable(grid1, list);
}
