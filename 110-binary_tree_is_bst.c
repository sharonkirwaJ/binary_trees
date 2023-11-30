#include "binary_trees.h"
/**
 * is_BST - function that checks if a binary tree
 * is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 * @min: the interval left edge, to check data for the
 * right child subtree.
 * @max: the interval right edge, to check data for the
 * left child subtree.
 * Return: 1 if the tree is validBST, 0 otherwise.
 */
int is_BST(const binary_tree_t *tree, int min, int max)
{
	if (tree == NULL)
	{
		return (1);
	}
	/**
	 * for the left child subtrees, the interval
	 *  will always [min , data-1] or not!
	 * for the right child subtrees, the interval
	 *  will always [data+1, max] or not!
	 */
	if (tree->n < min || tree->n > max)
	{
		return (0);
		/*if not*/
	}
	return (is_BST(tree->left, min, tree->n - 1)
	&& is_BST(tree->right, tree->n + 1, max));
}
/**
 * binary_tree_is_bst - function that checks if a binary tree
 * is a valid Binary Search Tree.
 * @tree: pointer to the root node of the tree to check.
 * Return: 1 if the tree is validBST, 0 otherwise.
 */
int binary_tree_is_bst(const binary_tree_t *tree)
{
	/**
	 * Properties of a Binary Search Tree:
	 * - The left subtree of a node contains only nodes
	 *   with values less than the node’s value
	 * - The right subtree of a node contains only nodes with
	 *   values greater than the node’s value
	 * - The left and right subtree each must also be a binary search tree
	 * - There must be no duplicate values
	 */
	int INT_MIN = -2147483648, INT_MAX = 2147483647;

	if (tree == NULL)
	{
		return (0);
	}

	return (is_BST(tree, INT_MIN, INT_MAX));
}
