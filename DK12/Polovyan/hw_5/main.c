#include <stdio.h>
#include "dk12_tool.h"

int main()
{
	floatTree *HW5 = createFloatTree(); // створюємо дерево

	insertFloatValueToTree(HW5, 17.2); // дадаємо єлементи у дерево
	insertFloatValueToTree(HW5, 24.1);
	insertFloatValueToTree(HW5, 8);
	insertFloatValueToTree(HW5, 97.0);
	insertFloatValueToTree(HW5, 3.3);
	insertFloatValueToTree(HW5, 7.97);
	insertFloatValueToTree(HW5, 4.32);
	insertFloatValueToTree(HW5, 1.00);

	printf("\n");
	printTree(HW5->root); // друкуємо єлементи дерева

	printf("\n\nNode : %.2f\n\n", findNodeWithValue(HW5, 4.32)->value); // знаходимо елемент у початковому дереві

	deleteValueFromTree(HW5, 24.1); // видаляємо єлементи дерева
	deleteValueFromTree(HW5, 7.97);

	printTree(HW5->root);																	  // друкуємо єлементи дерева, які залишились
	printf("\n\nNode %.2f still exist\n\n", findNodeWithValue(HW5, 4.32)->value); // знаходимо елемент в новому дереві
	deleteFloatTree(HW5); // видаляємо дерево
}
