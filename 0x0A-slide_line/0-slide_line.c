#include "slide_line.h"

/**
 * slide_left - slides an array to the left reproducing the game 2048 mechanics
 * @line: points to an array of integers containing size elements,
 * that must be slided & merged
 * @size: size of the elements contained in line
 * Return: 1 upon success, or 0 upon failure
 */
int slide_left(int *line, size_t size)
{
	size_t i, lnum_pos = 0;
	size_t first_zero = -1;
	int last_num = 0;

	for (i = 0; i < size; i++)
	{
		if (line[i] == 0 && (int)first_zero == -1)
			first_zero = i;
		if (line[i] != 0 && last_num == 0)
		{
			last_num = line[i];
			if ((int)first_zero != -1)
			{
				line[first_zero] = last_num;
				lnum_pos = first_zero;
				line[i] = 0;
			} else
			{
				lnum_pos = i;
			}
			continue;
		}
		if (line[i] != 0 && last_num != 0)
		{
			if (last_num == line[i])
			{
				line[lnum_pos] = last_num + line[i];
				last_num = 0;
				line[i] = 0;
				first_zero = lnum_pos + 1;
				last_num = 0;
			} else
			{
				last_num = 0;
			}
		}
	}
	return (1);
}

/**
 * slide_right - slides an array to the right reproducing the game
 * 2048 mechanics
 * @line: points to an array of integers containing size elements,
 * that must be slided & merged
 * @size: size of the elements contained in line
 * Return: 1 upon success, or 0 upon failure
 */
int slide_right(int *line, size_t size)
{
	size_t i, lnum_pos = 0;
	size_t first_zero = -1;
	int last_num = 0;

	for (i = size - 1; (int)i >= 0; i--)
	{
		if (line[i] == 0 && (int)first_zero == -1)
			first_zero = i;
		if (line[i] != 0 && last_num == 0)
		{
			last_num = line[i];
			if ((int)first_zero != -1)
			{
				line[first_zero] = last_num;
				lnum_pos = first_zero;
				line[i] = 0;
			} else
			{
				lnum_pos = i;
			}
			continue;
		}
		if (line[i] != 0 && last_num != 0)
		{
			if (last_num == line[i])
			{
				line[lnum_pos] = last_num + line[i];
				last_num = 0;
				line[i] = 0;
				first_zero = lnum_pos - 1;
				last_num = 0;
			} else
			{
				last_num = 0;
			}
		}
	}
	return (1);
}

/**
 * slide_line - reproduces the 2048 game mechanics on a single horizontal line
 *
 * @line: points to an array of integers containing size elements,
 * that must be slided & merged
 * @size: size of the elements contained in line
 * @direction: direction in which the elements of size will be merged
 * SLIDE_LEFT or SLIDE_RIGHT
 *
 * Return: 1 upon success, or 0 upon failure
 */
int slide_line(int *line, size_t size, int direction)
{


	if (direction != 0 && direction != 1)
	{
		return (0);
	}
	if (direction == 0)
	{
		return (slide_left(line, size));
	}
	if (direction == 1)
	{
		return (slide_right(line, size));
	}
	return (0);
}
