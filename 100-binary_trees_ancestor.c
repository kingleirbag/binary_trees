#include "binary_trees.h"

/**
 * binary_tree_depth - a function measures the depth of a node in a binary tree
 * @tree: is a pointer to the node to measure the depth
 * Return: if tree is NULL, function must return 0
 */
size_t binary_tree_depth(const binary_tree_t *tree)
{
	if (tree == NULL)
		return (0);
	else
		return (1 + binary_tree_depth(tree->parent));
}

/**
 * binary_trees_ancestor - a function that inds the lowest common ancestor
 * of two nodes
 * @first: first node
 * @second: second node
 * Return: lowest common ancestor
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *first,
				     const binary_tree_t *second)
{
	size_t first_hgt = 0, secon_hgt = 0;
	const binary_tree_t *aux = NULL;

	first_hgt = binary_tree_depth(first);
	secon_hgt = binary_tree_depth(second);
	if (first_hgt && secon_hgt)
	{
		if (first_hgt > secon_hgt)
		{
			aux = first;
			first = second;
			second = aux;
		}
		while (first)
		{
			aux = second;
			while (aux)
			{
				if (first == aux)
					return ((binary_tree_t *)first);
				aux = aux->parent;
			}
			first = first->parent;
		}
	}
	else
	{
		return (NULL);
	}
	return (NULL);
}
