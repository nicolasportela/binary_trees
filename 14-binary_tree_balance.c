#include "binary_trees.h"

/**
 * binary_tree_height - function that measures the height of a binary tree
 * @tree: pointer to the root node of the tree to measure the height
 * Return: 0 if tree is NULL
 */

size_t binary_tree_height(const binary_tree_t *tree)
{
	size_t left_height = 0;
	size_t right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL && tree->right == NULL)
	{
		return (0);
	}
	left_height = binary_tree_height(tree->left);
	left_height++;
	right_height = binary_tree_height(tree->right);
	right_height++;
	if (left_height > right_height)
	{
		return (left_height);
	}
	else
	{
		return (right_height);
	}
}

#include "binary_trees.h"

/**
 * binary_tree_balance - measures the balance factor of a binary tree
 * @tree: pointer to the root node of the tree to measure the balance factor
 * Return: 0 if tree is NULL
 */

int binary_tree_balance(const binary_tree_t *tree)
{
	int left_height = 0;
	int right_height = 0;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left == NULL)
	{
		left_height = left_height - 1;
	}
	else
	{
		left_height = binary_tree_height(tree->left);
	}

	if (tree->right == NULL)
	{
		right_height = right_height - 1;
	}
	else
	{
		right_height = binary_tree_height(tree->right);
	}

	return (left_height - right_height);
}
