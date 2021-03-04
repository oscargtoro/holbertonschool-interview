#include "menger.h"


/**
* menger - Draws a 2d menger sponge.
* @level: The level of menger sponge to draw
*/

void menger(int level)
{
	int side = pow(3, level), i, j, f, dim = 1;

	if (level < 0)
		return;
	if (level == 0)
	{
		printf("#\n");
		return;
	}
	if (level >= 1)
		dim = pow(3, level);
	for (i = 0; i < side; i++)
	{
		for (j = 0; j < side; j++)
		{
			for (f = dim / 3; f; f /= 3)
			{
				if ((i % (f * 3)) / f == 1 && (j % (f * 3)) / f == 1)
					break;
			}
			if (f)
			{
				printf(" ");
			}
			else
				printf("#");
		}
		printf("\n");
	}
}
