#include <stdio.h>
#include "dk12_tool.h"

int main()
{
	floatTree *LAB3 = createFloatTree(); // створюємо дерево

	insertFloatValueToTree(LAB3, 17.2); // дадаємо єлементи у дерево
	insertFloatValueToTree(LAB3, 24.1);
	insertFloatValueToTree(LAB3, 8);
	insertFloatValueToTree(LAB3, 97.0);
	insertFloatValueToTree(LAB3, 3.3);
	insertFloatValueToTree(LAB3, 7.97);
	insertFloatValueToTree(LAB3, 4.32);
	insertFloatValueToTree(LAB3, 1.00);

	printf("\n");
	printTree(LAB3->root); // друкуємо єлементи дерева

	printf("\n\nNode : %.2f\n\n", findNodeWithValue(LAB3, 4.32)->value); // знаходимо елемент у початковому дереві

	deleteValueFromTree(LAB3, 24.1); // видаляємо єлементи дерева
	deleteValueFromTree(LAB3, 7.97);

	printTree(LAB3->root);																	  // друкуємо єлементи дерева, які залишились
	printf("\n\nNode %.2f still exist\n\n", findNodeWithValue(LAB3, 4.32)->value); // знаходимо елемент в новому дереві
	deleteFloatTree(LAB3); // видаляємо дерево
}
