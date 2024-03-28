#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "binary_trees.h"

/**
 * print_t - Stores recursively each level in an array of strings
 * @tree: Pointer to the node to print
 * @offset: Offset to print
 * @depth: Depth of the node
 * @s: Buffer
 *
 * Return: length of the tree printed
 */
static int print_tree(const binary_tree_t *tree, int offset, int depth, char **s)
{
    char node_str[6];
    int node_width, left_width, right_width, is_left_child, i;

    if (!tree)
        return 0;

    is_left_child = (tree->parent && tree->parent->left == tree);
    node_width = sprintf(node_str, "(%03d)", tree->n);

    left_width = print_tree(tree->left, offset, depth + 1, s);
    right_width = print_tree(tree->right, offset + left_width + node_width, depth + 1, s);

    for (i = 0; i < node_width; i++)
        s[depth][offset + left_width + i] = node_str[i];

    if (depth && is_left_child)
    {
        for (i = 0; i < node_width + right_width; i++)
            s[depth - 1][offset + left_width + node_width / 2 + i] = '-';
        s[depth - 1][offset + left_width + node_width / 2] = '.';
    }
    else if (depth && !is_left_child)
    {
        for (i = 0; i < left_width + node_width; i++)
            s[depth - 1][offset - node_width / 2 + i] = '-';
        s[depth - 1][offset + left_width + node_width / 2] = '.';
    }

    return left_width + node_width + right_width;
}

/**
 * _height - Measures the height of a binary tree
 *
 * @tree: Pointer to the node
 * Return: The height of the tree
 */
static size_t _height(const binary_tree_t *tree)
{
	size_t height_left = 0;
	size_t height_right = 0;

if (tree->left)
    height_left = 1 + _height(tree->left);

if (tree->right)
    height_right = 1 + _height(tree->right);

return (height_left > height_right ? height_left : height_right);
}

/**
 * binary_tree_print - Prints a binary tree
 * @tree: Pointer to the root node of the tree
 */
void binary_tree_print(const binary_tree_t *tree)
{
	char **s;
	size_t height, i, j;

	if (!tree)
		return;
	height = _height(tree);
	s = malloc(sizeof(*s) * (height + 1));
	if (!s)
		return;
	for (i = 0; i < height + 1; i++)
	{
		s[i] = malloc(sizeof(**s) * 255);
		if (!s[i])
			return;
		memset(s[i], 32, 255);
	}
	print_t(tree, 0, 0, s);
	for (i = 0; i < height + 1; i++)
	{
		for (j = 254; j > 1; --j)
		{
			if (s[i][j] != ' ')
				break;
			s[i][j] = '\0';
		}
		printf("%s\n", s[i]);
		free(s[i]);
	}
	free(s);
}
