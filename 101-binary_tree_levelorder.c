#include "binary_trees.h"

/**
 * binary_tree_levelorder - this traverses a binary
 * tree using level-order traverse
 * @tree: the tree to traverse
 * @func: the pointer to a function to call for each node
 *
 * Return: returns nothing
 */
void binary_tree_levelorder(const binary_tree_t *tree, void (*func)(int))
{
	size_t level, maxlevel;

	if (!tree || !func)
		return;

	maxlevel = binary_tree_height(tree) + 1;
	level = 1;
	while (level <= maxlevel)
	{
		btlo_helper(tree, func, level);
		level++;
	}
}

/**
 * btlo_helper - this function goes through a
 * binary tree using post-order traverse
 * @tree: the tree to traverse
 * @func: the pointer to a function to call for each node
 * @level: the level of the tree to call func upon
 *
 * Return: returns nothing
 */
void btlo_helper(const binary_tree_t *tree, void (*func)(int), size_t level)
{
	if (level == 1)
		func(tree->n);
	else
	{
		btlo_helper(tree->left, func, level - 1);
		btlo_helper(tree->right, func, level - 1);
	}
}

/**
 * binary_tree_height - this function measures the height of a binary tree
 * @tree: the tree to measure the height of
 *
 * Return: returns the height of the tree, 0 if tree is NULL
 */
size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t height_l = 0;
	size_t height_r = 0;

	if (!tree)
		return (0);

	height_l = tree->left ? 1 + binary_tree_height(tree->left) : 0;
	height_r = tree->right ? 1 + binary_tree_height(tree->right) : 0;
	return (height_l > height_r ? height_l : height_r);
}
