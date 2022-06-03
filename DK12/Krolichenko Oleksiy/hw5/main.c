#define _CRT_SECURE_NO_WARNINGS
#include "dk_tool.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
	SetConsoleCP(1251);
	SetConsoleOutputCP(1251);
	doubleTree* tree = createTree();

	insertValue(tree, 1.1);
	insertValue(tree, 2.2);
	insertValue(tree, 3.3);

	printTree(tree->root);
	findValue(tree, 3.3)->value;

	deleteValue(tree, 3.3);
	printf("\nНове дерево:\n");
	printf("\n");
	printTree(tree->root);
	findValue(tree, 3.3)->value;
	deleteTree(tree);
}