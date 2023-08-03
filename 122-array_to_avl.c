#include "binary_trees.h"

/**
 * array_to_avl - a function that builds an AVL tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is the number of element in the array
 * Return: pointer to the root node of the created AVL tree, or NULL on failure
 */
avl_t *array_to_avl(int *array, size_t size)
{
	avl_t *a_tree = NULL;
	size_t index, counter;

	if (array == NULL)
		return (NULL);

	for (index = 0; index < size; index++)
	{
		for (counter = 0; counter < index; counter++)
		{
			if (array[counter] == array[index])
				break;
		}
		if (counter == index)
		{
			if (avl_insert(&a_tree, array[index]) == NULL)
				return (NULL);
		}
	}

	return (a_tree);
}
