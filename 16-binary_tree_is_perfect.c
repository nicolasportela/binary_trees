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

/**
 * binary_tree_size - measures the size of a binary tree
 * @tree: pointer to the root node of the tree to measure the size
 * Return: 0 if tree is NULL
 */

size_t binary_tree_size(const binary_tree_t *tree)
{
	size_t size = 1;

	if (tree == NULL)
	{
		return (0);
	}

	if (tree->left != NULL)
	{
		size = size + binary_tree_size(tree->left);
	}
	if (tree->right != NULL)
	{
		size = size + binary_tree_size(tree->right);
	}
	return (size);
}

/**
 * _pow_recursion - recursive function
 * @x: base number
 * @y: power number
 * Return: float
 */

float _pow_recursion(float x, float y)
{
	if (y == 0) /* base case */
		return (1);
	if (y < 0)
		return (_pow_recursion(x, y + 1) / x);

	return (_pow_recursion(x, y - 1) * x);
}

/**
 * binary_tree_is_perfect - function that checks if a binary tree is perfect
 * @tree: pointer to the root node of the tree to check
 * Return: 0 if tree is NULL
 */

int binary_tree_is_perfect(const binary_tree_t *tree)
{
	int size;
	int height;
	int max;

	if (tree == NULL)
	{
		return (0);
	}

	height = binary_tree_height(tree);
	size = binary_tree_size(tree);
	max = _pow_recursion(2, height + 1) - 1;
	if (max == size)
		return (1);
	else
		return (0);
}
