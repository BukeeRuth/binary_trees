#include "binary_trees.h"

/**
 * binary_trees_ancestor - Finds the lowest common ancestor of two nodes.
 *
 * @node_a: A pointer to the first node.
 * @node_b: A pointer to the second node.
 *
 * Return: A pointer to the lowest common ancestor node of the two given nodes.
 *         If no common ancestor was found, your function must return NULL.
 */
binary_tree_t *binary_trees_ancestor(const binary_tree_t *node_a,
		const binary_tree_t *node_b)
{
	binary_tree_t *ancestor_a, *ancestor_b;

	if (!node_a || !node_b)
		return (NULL);
	if (node_a == node_b)
		return ((binary_tree_t *)node_a);

	ancestor_a = node_a->parent, ancestor_b = node_b->parent;
	if (node_a == ancestor_b || !ancestor_a || (!ancestor_a->parent && ancestor_b))
		return (binary_trees_ancestor(node_a, ancestor_b));
	else if (ancestor_a == node_b || !ancestor_b || (!ancestor_b->parent && ancestor_a))
		return (binary_trees_ancestor(ancestor_a, node_b));

	return (binary_trees_ancestor(ancestor_a, ancestor_b));
}

