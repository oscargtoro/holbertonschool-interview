#include "binary_trees.h"

/**
 * sorted_array_to_avl - builds an AVL tree from an array
 *
 * @array: pointer to the first element of the array to be converted
 * @size: the number of element in the array
 *
 * Return: a pointer to the root node of the created AVL tree,
 * or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *avl = NULL;
	size_t i = 0;

	for (i = 0; i < size; i++)
	{
		avl->n = *array;
	}


	return (avl);
}
