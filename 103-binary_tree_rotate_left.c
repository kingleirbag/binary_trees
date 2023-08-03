#include "binary_trees.h"

/**
 * binary_tree_rotate_left - a function that performs a left-rotation
 * on a binary tree
 * @tree: pointer to binary_tree_t
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *rot, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->right)
	{
		temp = tree->right->left;
		rot = tree->right;
		rot->parent = tree->parent;
		rot->left = tree;
		tree->parent = rot;
		tree->right = temp;
		if (temp)
			temp->parent = tree;
		return (rot);
	}
	return (NULL);
}
