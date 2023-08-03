#include "binary_trees.h"

/**
 * array_to_bst - a function that builds a Binary Search Tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is a pointer to the first element of the array to be converted
 * Return: is a pointer to the first element of the array to be converted
 */

bst_t *array_to_bst(int *array, size_t size)
{
	bst_t *b_tree;
	size_t counter;

	if (array == NULL)
		return (NULL);
	b_tree = NULL;
	for (counter = 0; counter < size; counter++)
	{
		bst_insert(&b_tree, array[counter]);
	}
	return (b_tree);
}