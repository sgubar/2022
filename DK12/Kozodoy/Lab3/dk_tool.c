#define _CRT_SECURE_NO_WARNINGS
#define _USE_MATH_DEFINES
#include "dk_tool.h"
#include <stdlib.h>
#include <stdio.h>

Tree* createTree()
{
	Tree* tree = (Tree*)malloc(sizeof(Tree));
	tree->size = 0;
	tree->root = NULL;
	return tree;
}

void deleteNode(Node* node)
{
	if (node != NULL)
	{
		deleteNode(node->left);
		deleteNode(node->right);
		free(node);
	}
}

void deleteTree(Tree* tree)
{
	if (tree != NULL)
	{
		deleteNode(tree->root);
		free(tree);
	}
}

void addElement(Tree* tree, float value)
{
	Node* parent = tree->root;
	Node* elem = (Node*)malloc(sizeof(Node));
	elem->value = value;
	elem->left = NULL;
	elem->right = NULL;
	if (parent == NULL)
	{
		tree->root = elem;
		elem->parent = NULL;
		tree->size++;
		return 1;
	}
	while (parent != NULL)
	{
		if (value > parent->value)
		{
			if (parent->right != NULL)
			{
				parent = parent->right;
				continue;
			}
			else
			{
				parent->right = elem;
				elem->parent = parent;
				break;
			}
		}
		else if (value < parent->value)
		{
			if (parent->left != NULL)
			{
				parent = parent->left;
				continue;
			}
			else
			{
				parent->left = elem;
				elem->parent = parent;
				break;
			}
		}
		else
		{
			printf("This element is already in the tree!\n");
			return -1;
		}
	}
	tree->size++;
}

void inputElement(Tree* tree)
{
	printf("(0 to exit or letter to fast close)\n");
	float value = 1;
	while (value)
	{
		value = 0;
		printf("Enter float element: ");
		scanf_s("%f", &value, 1);
		if (value == 0)
		{
			break;
		}
		addElement(tree, value);
	}
}

Node* getElement(Tree* tree, float value)
{
	Node* elem = tree->root;
	while (elem != NULL)
	{
		if (elem->value > value)
		{
			elem = elem->left;
			continue;
		}
		else if (elem->value < value)
		{
			elem = elem->right;
			continue;
		}
		else
		{
			return elem;
		}
	}
	return NULL;
}

void delElementByValue(Tree* tree, float value)
{
	Node* elem = getElement(tree, value);
	if (elem == NULL)
	{
		printf("ERROR! Element not found!\n");
		return -1;
	}
	if (elem->left != NULL && elem->right != NULL)
	{
		Node* ins = elem->left;
		while (ins->right != NULL)
		{
			ins = ins->right;
		}
		float BUFF = ins->value;
		printf("Inserted element: %.2f\n", ins->value);
		delElementByValue(tree, ins->value);
		elem->value = BUFF;
		return 2;
	}
	else if (elem->left != NULL)
	{
		if (elem == elem->parent->left)
		{
			elem->parent->left = elem->left;
		}
		else
		{
			elem->parent->right = elem->left;
		}
	}
	else if (elem->right != NULL)
	{
		if (elem == elem->parent->right)
		{
			elem->parent->right = elem->right;
		}
		else
		{
			elem->parent->left = elem->right;
		}
	}
	else
	{
		if (elem == elem->parent->right)
		{
			elem->parent->right = NULL;
		}
		else
		{
			elem->parent->left = NULL;
		}
	}
	tree->size--;
	return 1;
}

void delElement(Tree* tree)
{
	float value = 0;
	printf("\nEnter value to delete: ");
	scanf_s("%f", &value);
	delElementByValue(tree, value);
}

void printElement(Node* node)
{
	if (node != NULL)
	{
		printf("%.2f  ", node->value);
		printElement(node->left);
		printElement(node->right);
	}
}

void printTree(Tree* tree)
{
	if (tree != NULL)
	{
		if (tree->size == 0)
		{
			return -1;
		}
		printf("\nTree size: %d\n", tree->size);
		printElement(tree->root);
		printf("\n");
	}
}