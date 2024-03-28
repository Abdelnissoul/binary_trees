#include "binary_trees.h"

/**
 * bst_insert - Inserts a value in a Binary Search Tree.
 * @tree: A double pointer to the root node of the BST to insert the value.
 * @value: The value to store in the node to be inserted.
 * Return: A pointer to created node, or NULL on (failure).
 */
bst_t *bst_insert(bst_t **tree, int value)
{
	bst_t *gleb, *yeni;

	if (tree != NULL)
	{
		gleb = *tree;

		if (gleb == NULL)
		{
			yeni = binary_tree_node(gleb, value);
			if (yeni == NULL)
				return (NULL);
			return (*tree = yeni);
		}

		if (value < gleb->n)
		{
			if (gleb->left != NULL)
				return (bst_insert(&gleb->left, value));

			yeni = binary_tree_node(gleb, value);
			if (yeni == NULL)
				return (NULL);
			return (gleb->left = yeni);
		}
		if (value > gleb->n)
		{
			if (gleb->right != NULL)
				return (bst_insert(&gleb->right, value));

			yeni = binary_tree_node(gleb, value);
			if (yeni == NULL)
				return (NULL);
			return (gleb->right = yeni);
		}
	}
	return (NULL);
}
