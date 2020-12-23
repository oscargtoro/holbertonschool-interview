#include "binary_trees.h"
#include <stdio.h>

void check_heap(heap_t **, heap_t *);
/**
 * heap_insert - Inserts a value into a Max Binary Heap.
 * @root: Double pointer to the root node of the Heap.
 * @value: The value store in the node to be inserted.
 * Return: A pointer to the inserted node, or NULL on failure.
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *new_node;

	new_node = malloc(sizeof(heap_t));
	if (new_node == NULL)
		return (NULL);
	new_node->n = value;
	new_node->parent = NULL;
	new_node->left = NULL;
	new_node->right = NULL;
	if ((*root) == NULL)
	{
		*root = new_node;
		return (new_node);
	}
	check_heap(&(*root), new_node);
	return (new_node);
}

/**
 * check_heap - Traverses the Max Binary Heap tree and inserts the new node
 * @parent: Max Binary Heap tree to traverse
 * @new_node: Node to insert in the Max Binary Heap tree
 */
void check_heap(heap_t **parent, heap_t *new_node)
{
	if (*parent == NULL)
		return;
	if ((*parent)->n <= new_node->n)
	{
		new_node->parent = (*parent)->parent;
		new_node->left = (*parent);
		(*parent)->parent = new_node;
		(*parent) = new_node;
		return;
	}
	if ((*parent)->left == NULL)
	{
		(*parent)->left = new_node;
		new_node->parent = (*parent);
		return;
	}
	if ((*parent)->right == NULL)
	{
		(*parent)->right = new_node;
		new_node->parent = (*parent);
		return;
	}
	check_heap(&(*parent)->left, new_node);
	/*
	*if (*parent == NULL)
	*	return;
	*check_heap(&(*parent)->left, new_node);
	*check_heap(&(*parent)->right, new_node);
	*if ()
	*/
}

/* void heap_sort() */
