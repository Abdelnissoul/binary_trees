#include "binary_trees.h"

/**
 * binary_tree_rotate_left - Left-rotates a binary tree.
 * @tree: A pointer to the root node to rotate
 * Return: A pointer to the new root node.
 */
binary_tree_t *binary_tree_rotate_left(binary_tree_t *tree)
{
	binary_tree_t *ennes, *ptr;

	if (tree == NULL || tree->right == NULL)
		return (NULL);

	ennes = tree->right;
	ptr = ennes->left;
	ennes->left = tree;
	tree->right = ptr;
	if (ptr != NULL)
		ptr->parent = tree;
	ptr = tree->parent;
	tree->parent = ennes;
	ennes->parent = ptr;
	if (ptr != NULL)
	{
		if (ptr->left == tree)
			ptr->left = ennes;
		else
			ptr->right = ennes;
	}

	return (ennes);
}
