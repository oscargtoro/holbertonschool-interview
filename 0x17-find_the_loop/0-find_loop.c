#include "lists.h"

/**
 * find_listint_loop - finds the loop in a linked list.
 *
 * @head: Search starting point.
 *
 * Return: The address of the node where the loop starts, or NULL if there is
 * no loop.
 */
listint_t *find_listint_loop(listint_t *head)
{
	/*
	*void *buffer[1024];
	*int n = 0, i = 0;
	*/

	if (!head)
		return (NULL);
	/*
	* while (head)
	*{
	*	for (i = 0; i < n; i++)
	*	{
	*		if (head == buffer[i])
	*			return (head);
	*	}
	*	buffer[n] = head;
	*	head = head->next;
	*	n++;
	*}
	*/
	return (NULL);
}
