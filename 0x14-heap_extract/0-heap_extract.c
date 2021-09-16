#include "binary_trees.h"

/**
 * rearange - rebuilds tree
 *
 * @root: root of max binary heap tree
 * @temp: node to swap
 * @right: direction of the check
 **/
void rearange(heap_t **root, heap_t **temp, int right)
{
	if (right)
	{
		if ((*temp)->right)
			(*temp)->right = (*root)->right;
		(*temp)->left = (*root)->left;
		(*temp)->left->parent = (*temp);
		if (!(*root)->parent)
		{
			free(*root);
			(*temp)->parent = NULL;
		}
		else
			(*temp)->parent = *root;
		(*root) = (*temp);
	}
	else
	{

		if ((*temp)->left)
			(*temp)->left = (*root)->left;
		(*temp)->right = (*root)->right;
		(*temp)->right->parent = (*temp);
		if (!(*root)->parent)
		{
			free(*root);
			(*temp)->parent = NULL;
		}
		else
			(*temp)->parent = *root;
		(*root) = (*temp);
	}
}

/**
 * heap_extract - extracts the root node of a Max Binary Heap.
 *
 * @root: double pointer to the root node of the heap.
 *
 * Return: The value stored in the extracted root node, 0 on failure.
 **/
int heap_extract(heap_t **root)
{
	int root_n = (*root)->n;
	heap_t *temp;

	if (!root)
		return (0);
	if (!(*root)->left && !(*root)->right)
	{
		if (!(*root)->parent)
		{
			free(*root);
			*root = NULL;
		}
		return (root_n);
	}
	else if ((*root)->right && !(*root)->left)
	{
		temp = (*root)->right;
		heap_extract(&(*root)->right);
		*root = (*root)->right;
	}
	else if ((*root)->left && !(*root)->right)
	{
		temp = (*root)->right;
		heap_extract(&(*root)->left);
		*root = (*root)->left;
	}
	else if ((*root)->right->n > (*root)->left->n)
	{
		temp = (*root)->right;
		heap_extract(&(*root)->right);
		rearange(root, &temp, 1);
	}
	else if ((*root)->left->n > (*root)->right->n)
	{
		temp = (*root)->left;
		heap_extract(&(*root)->left);
		rearange(root, &temp, 0);
	}
	return (root_n);
}
