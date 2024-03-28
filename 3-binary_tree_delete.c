#include "binary_trees.h"

/**
 * binary_tree_delete - this function deletes an entire binary tree
 * @tree: the tree to delete
 * 
 * Return: returns nothing
 */
void binary_tree_delete(binary_tree_t *tree)
{
	if (!tree)
		return;
	binary_tree_delete(tree->right);
	binary_tree_delete(tree->left);
	free(tree);
}
