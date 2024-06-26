#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full or not
 * @tree: a pointer to the root node of the tree to check
 *
 * Return: returns 1 if the tree is full, 0 if the tree is not full
 * 0 if tree is NULL
 */
int binary_tree_is_full(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	if (!tree->right && !tree->left)
		return (1);

	if (tree->right && tree->left)
		return (binary_tree_is_full(tree->left) &&
			binary_tree_is_full(tree->right));

	return (0);
}
