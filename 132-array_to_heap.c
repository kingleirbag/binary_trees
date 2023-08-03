#include "binary_trees.h"

/**
 * array_to_heap - a function that builds a Max Binary Heap tree from an array
 * @array: is a pointer to the first element of the array to be converted
 * @size: is a pointer to the first element of the array to be converted
 * Return: pointer to the root node of the created Binary Heap else NULL fail
 */
heap_t *array_to_heap(int *array, size_t size)
{
	heap_t *b_tree;
	size_t i;

	b_tree = NULL;

	for (i = 0; i < size; i++)
	{
		heap_insert(&b_tree, array[i]);
	}

	return (b_tree);
}
