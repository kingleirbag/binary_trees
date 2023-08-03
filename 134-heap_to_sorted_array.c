#include "binary_trees.h"

/**
 * count_h_nodes - a function that counts the number of nodes inside a tree
 * @root: Pointer to tree's root node
 * Return: Number of tree nodes
 */
int count_h_nodes(binary_tree_t *root)
{
	if (!root)
		return (0);

	return (1 + count_h_nodes(root->left) +
		    count_h_nodes(root->right));
}

/**
 * heap_to_sorted_array - a function that converts a Binary Max Heap
 * to a sorted array of integers
 * @heap: Pointer to heap's node
 * @size: Pointer to arrays size
 * Return: Pointer to array
 */
int *heap_to_sorted_array(heap_t *heap, size_t *size)
{
	int i, nodes, *arr = NULL;

	*size = 0;
	if (!heap)
		return (NULL);

	nodes = count_h_nodes(heap);
	arr = malloc(sizeof(*arr) * nodes);
	if (!arr)
		return (NULL);

	*size = nodes;
	for (i = 0; i < nodes; i++)
		arr[i] = heap_extract(&heap);

	return (arr);
}
