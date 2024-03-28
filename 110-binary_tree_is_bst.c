#include "binary_trees.h"

/**
 * binary_tree_is_bst - this function checks if a binary
 * tree is a valid Binary Search Tree
 * @tree: the pointer to the root node of the tree to check
 *
 * Return: returns 1 if tree is a valid BST
 * 0 otherwise
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	if (!tree)
		return (0);
	return (btib_helper(tree, INT_MIN, INT_MAX));
}

/**
 * btib_helper - this function checks if a binary tree
 * is a valid Binary Search Tree
 * @tree: the  pointer to the root node of the tree to check
 * @min: the Lower bound of checked nored
 * @max: the Upper bound of checked nodes
 *
 * Return: returns 1 if tree is a valid BST
 * 0 otherwise
 */
int btib_helper(const binary_tree_t *tree, int min, int max)
{
	if (!tree)
		return (1);

	if (tree->n < min || tree->n > max)
		return (0);

	return (btib_helper(tree->left, min, tree->n - 1) &&
		btib_helper(tree->right, tree->n + 1, max));
}
