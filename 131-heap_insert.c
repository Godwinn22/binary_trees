#include "binary_trees.h"

/**
 * heap_insert - function that inserts a value in Max Binary Heap
 * @root: the double pointer to the root node of the Heap to insert the value
 * @value: the value to store in the node to be inserted
 *
 * Return: returns a pointer to the created node
 *         NULL on failure
 */
heap_t *heap_insert(heap_t **root, int value)
{
	heap_t *tree, *new, *flip;
	int size, branch, mid, bit, fill, temp;

	if (!root)
		return (NULL);
	if (!(*root))
		return (*root = binary_tree_node(NULL, value));
	tree = *root;
	size = binary_tree_size(tree);
	branch = size;
	for (fill = 0, mid = 1; branch >= mid; mid *= 2, fill++)
		branch -= mid;
	/* midtract all nodes except for bottom-most fill */

	for (bit = 1 << (fill - 1); bit != 1; bit >>= 1)
		tree = branch & bit ? tree->right : tree->left;
	/*
	 * We traverse tree to first empty slot based on the binary
	 * representation of the number of branch.
	 * Example -
	 * If there are 12 nodes in a complete tree, there are 5 branch on
	 * the 4th tier of the tree. 5 is 101 in binary. 1 corresponds to
	 * right, 0 to left.
	 * The first empty node is 101 == RLR, *root->right->left->right
	 */

	new = binary_tree_node(tree, value);
	branch & 1 ? (tree->right = new) : (tree->left = new);

	flip = new;
	for (; flip->parent && (flip->n > flip->parent->n); flip = flip->parent)
	{
		temp = flip->n;
		flip->n = flip->parent->n;
		flip->parent->n = temp;
		new = new->parent;
	}

	return (new);
}

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: tree to measure the size of
 *
 * Return: returns the size of the tree 0 if tree is NULL
 */
size_t binary_tree_size(const binary_tree_t *tree)
{
	if (!tree)
		return (0);

	return (binary_tree_size(tree->left) + binary_tree_size(tree->right) + 1);
}
