#include "binary_trees.h"

/**
 * *binary_tree_insert_right - inserts node as the right-child of another node
 * @parent: pointer to the node to insert the right-child in
 * @value: value to store in the new node
 * Return: pointer to the created node, or NULL on failure or if parent is NULL
 */

binary_tree_t *binary_tree_insert_right(binary_tree_t *parent, int value)
{
	binary_tree_t *new_right = NULL;

	if (parent == NULL)
	{
		return (NULL);
	}
	new_right = malloc(sizeof(binary_tree_t));
	if (new_right == NULL)
	{
		return (NULL);
	}
	new_right->parent = parent;
	new_right->n = value;
	new_right->left = NULL;
	new_right->right = NULL;
	if (parent->right != NULL)
	{
		new_right->right = parent->right;
		new_right->right->parent = new_right;
	}
	parent->right = new_right;
	return (new_right);
}
