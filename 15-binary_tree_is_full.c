#include "binary_trees.h"

/**
 * binary_tree_is_full - function that checks if a binary tree is full
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */

int binary_tree_is_full(const binary_tree_t *tree)
{
	int a;
	int b;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left != NULL && tree->right != NULL)
	{
		a = binary_tree_is_full(tree->left);
		b = binary_tree_is_full(tree->right);
		if (a == 1 && b == 1)
		{
			return (1);
		}
	}
	else if (tree->left == NULL && tree->right == NULL)
	{
		return (1);
	}
	return (0);
}
