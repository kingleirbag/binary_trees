#include "binary_trees.h"

/**
 * binary_tree_rotate_right -  a function that performs a
 * right-rotation on a binary tree
 * @tree: pointer to binary_tree_t
 * Return: pointer to the new root node of the tree once rotated
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *rotation, *temp;

	if (tree == NULL)
		return (NULL);
	if (tree->left)
	{
		temp = tree->left->right;
		rotation = tree->left;
		rotation->parent = tree->parent;
		rotation->right = tree;
		tree->parent = rotation;
		tree->left = temp;
		if (temp)
			temp->parent = tree;
		return (rotation);
	}
	return (NULL);
}
