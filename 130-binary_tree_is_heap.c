#include "binary_trees.h"
#include "102-binary_tree_is_complete.c"

/**
 * max_check - Goes through a binary tree checking root as max value
 * @tree: Pointer to the root
 * Return: 1 if all nodes are max, 0 in other cases
 **/
int max_check(const binary_tree_t *tree)
{
	int left_check = 1, right_check = 1;

	if (!tree)
		return (0);
	if (!tree->left && !tree->right)
		return (1);
	if (tree->left)
	{
		if (tree->n <= tree->left->n)
			return (0);
		left_check = max_check(tree->left);
	}
	if (tree->right)
	{
		if (tree->n <= tree->right->n)
			return (0);
		right_check = max_check(tree->right);
	}
	return (left_check && right_check);
}

/**
 * binary_tree_is_heap - Checks if a binary tree is a heap
 * @tree: Pointer to the node
 * Return: 1 in case BST /  0 otherwise
 **/
int binary_tree_is_heap(const binary_tree_t *tree)
{
	int complete_check;

	if (!tree)
		return (0);

	complete_check = binary_tree_is_complete(tree);
	if (!complete_check)
		return (0);

	return (max_check(tree));
}
