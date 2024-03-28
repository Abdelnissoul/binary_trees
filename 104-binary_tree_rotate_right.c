#include "binary_trees.h"

/**
 * binary_tree_rotate_right - Right-rotates a binary tree.
 * @tree: A pointer to the root node of the tree to rotate.
 *
 * Return: A pointer to the new root node after rotation.
 */
binary_tree_t *binary_tree_rotate_right(binary_tree_t *tree)
{
	binary_tree_t *ennes, *ptr;

	if (tree == NULL || tree->left == NULL)
		return (NULL);

	ennes = tree->left;
	ptr = ennes->right;
	ennes->right = tree;
	tree->left = ptr;
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
