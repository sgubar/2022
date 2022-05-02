#include <stdio.h>
#include "dk12_tool.h"

int main()
{
	intTree *LAB3 = createIntTree(); // створюємо дерево

	insertIntValueToTree(LAB3, 17); // дадаємо єлементи у дерево
	insertIntValueToTree(LAB3, 2);
	insertIntValueToTree(LAB3, 8);
	insertIntValueToTree(LAB3, 97);
	insertIntValueToTree(LAB3, 3);
	insertIntValueToTree(LAB3, 7);
	insertIntValueToTree(LAB3, 4);
	insertIntValueToTree(LAB3, 1);

	printf("\n");
	printTree(LAB3->root); // друкуємо єлементи дерева

	printf("\n\nNode : %d\n\n", findNodeWithValue(LAB3, 2)->value); // знаходимо елемент у початковому дереві

	deleteValueFromTree(LAB3, 97); // видаляємо єлементи дерева
	deleteValueFromTree(LAB3, 7);

	printTree(LAB3->root);																	  // друкуємо єлементи дерева, які залишились
	printf("\n\nNode %d still exist\n\n", findNodeWithValue(LAB3, 2)->value); // знаходимо елемент в новому дереві
	deleteIntTree(LAB3); // видаляємо дерево
}
