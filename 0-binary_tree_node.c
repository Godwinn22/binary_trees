#include "binary_trees.h"

/**
 * binary_tree_node - function that creates a binary tree node
 * @parent: the pointer to the parent node of the node to create
 * @value: the value to put in the new node
 *
 * Return: returns the pointer to the newly created node,
 * NULL on failure
 */
binary_tree_t *binary_tree_node(binary_tree_t *parent, int value)
{
	binary_tree_t *new;

	new = malloc(sizeof(binary_tree_t));
	if (!new)
		return (NULL);
	new->n = value;
	new->parent = parent;
	new->left = NULL;
	new->right = NULL;
	return (new);
}
