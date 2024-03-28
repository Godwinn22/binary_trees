#include "binary_trees.h"

/**
 * array_to_heap - function that builds a Max Binary
 * Heap tree from an array
 * @array: the pointer to the first element of the array
 * that is to be converted
 * @size: the number of element in the array
 *
 * Return: returns a pointer to the root node of the
 * Binary Heap that is created, NULL on failure
 */
heap_t *array_to_heap(int *array, size_t size)
{
	unsigned int i;
	heap_t *root = NULL;

	i = 0;
	while (i < size)
	{
		heap_insert(&root, array[i]);
		i++;
	}

	return (root);
}
