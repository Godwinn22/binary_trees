#include "binary_trees.h"

/**
 * binary_tree_sibling - this function finds the sibling of a node
 * @node: the pointer to the node to find the sibling
 *
 * Return: returns the pointer to the sibling node,NULL if node is NULL
 * ,NULL if the parent is NULL,NULL if the node has no siblings
 */
binary_tree_t *binary_tree_sibling(binary_tree_t *node)
{
	if (!node || !node->parent)
		return (NULL);

	if (node == node->parent->left)
		return (node->parent->right);
	return (node->parent->left);
}
