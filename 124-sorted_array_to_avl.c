#include "binary_trees.h"
/**
 * aux_sort - A function that create the tree using the
 * half element of the array
 * @parent: parent of the node to create
 * @array: sorted array
 * @begin: position where the array starts
 * @last: position where the array ends
 * Return: tree created
 */
avl_t *aux_sort(avl_t *parent, int *array, int begin, int last)
{
	avl_t *root;
	binary_tree_t *aux;
	int midian = 0;

	if (begin <= last)
	{
		midian = (begin + last) / 2;
		aux = binary_tree_node((binary_tree_t *)parent, array[midian]);
		if (aux == NULL)
			return (NULL);
		root = (avl_t *)aux;
		root->left = aux_sort(root, array, begin, midian - 1);
		root->right = aux_sort(root, array, midian + 1, last);
		return (root);
	}
	return (NULL);
}
/**
 * sorted_array_to_avl - a function that builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: pointer to the root node of the created AVL tree or NULL on failure
 */
avl_t *sorted_array_to_avl(int *array, size_t size)
{
	if (array == NULL || size == 0)
		return (NULL);
	return (aux_sort(NULL, array, 0, ((int)(size)) - 1));
}