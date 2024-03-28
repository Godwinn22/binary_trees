#include "binary_trees.h"

/**
 * binary_tree_size - this function measures the size of a binary tree
 * @tree: the tree to measure the size of
 *
 * Return: returns the size of the tree, 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
