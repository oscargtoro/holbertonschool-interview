#include "search_algos.h"
/**
* advanced_binary - searches for a value in a sorted array of integers.
* @array: pointer to the first element of the array to search in
* @size: number of elements in array
* @value: value to search for
* Return: idx where value is located, -1 otherwise
*/
int advanced_binary(int *array, size_t size, int value)
{
	size_t i, mid, idx = 0;
	int tmp;

	if (array == NULL)
		return (-1);

	printf("Searching in array: ");
	for (i = 0; i < size; i++)
	{
		if (i == size - 1)
			printf("%d\n", array[i]);
		else
			printf("%d, ", array[i]);
	}

	if (size == 1 && array[0] != value)
		return (-1);
	mid = (size - 1) / 2;
	if (array[mid] == value)
	{
		idx += mid + 1;
		array += mid + 1;
		if (size % 2 != 0)
			mid--;
	}
	mid++;
	tmp = advanced_binary(array, mid, value);
	if (tmp != -1)
		return (tmp + idx);
	return (-1);
}
