#include "binary_trees.h"

/**
 * sorted_array_to_avl - a function that builds
 * an AVL tree from an array
 * @array: the pointer to the first element of the array to be converted
 * @size: the number of elements in the array
 *
 * Return: returns a pointer to the root node of the created AVL tree
 * NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	avl_t *tree = NULL;
	size_t mid;

	if (!array)
		return (NULL);
	mid = (size - 1) / 2;
	tree = binary_tree_node(NULL, array[mid]);

	sata_helper(&tree, array, -1, mid);
	sata_helper(&tree, array, mid, size);

	return (tree);
}

/**
 * sata_helper - a helper function that builds an AVL tree from an array
 * @root: the double pointer to the root node of the subtree
 * @array: a pointer to the first element of the array to be converted
 * @lo: the lower bound index
 * @hi: the upper bound index
 */
void sata_helper(avl_t **root, int *array, size_t lo, size_t hi)
{
	avl_t *new = NULL;
	size_t mid;

	if (hi - lo > 1)
	{
		mid = (hi - lo) / 2 + lo;
		new = binary_tree_node(*root, array[mid]);
		if (array[mid] > (*root)->n)
			(*root)->right = new;
		else if (array[mid] < (*root)->n)
			(*root)->left = new;
		sata_helper(&new, array, lo, mid);
		sata_helper(&new, array, mid, hi);
	}
}
