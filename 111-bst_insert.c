#include "binary_trees.h"
/**
 * bst_insert -  a function that inserts a value in a Binary Search Tree
 * @tree: s a double pointer to the root node of the BST to insert the value
 * @value: is the value to store in the node to be inserted
 * Return: Always 0 (Success)
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *b_tree = NULL;

	if (tree == NULL)
		return (NULL);
	if (*tree == NULL)
	{
		*tree = binary_tree_node(NULL, value);
		return (*tree);
	}
	b_tree = *tree;
	if (value < b_tree->n)
	{
		if (b_tree->left == NULL)
		{
			b_tree->left = binary_tree_node(b_tree, value);
			return (b_tree->left);
		}
		return (bst_insert(&(b_tree->left), value));
	}
	if (value > b_tree->n)
	{
		if (b_tree->right == NULL)
		{
			b_tree->right = binary_tree_node(b_tree, value);
			return (b_tree->right);
		}
		return (bst_insert(&(b_tree->right), value));
	}
	return (NULL);
}