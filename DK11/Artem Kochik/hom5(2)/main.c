#include <stdio.h>
#include "dk11_tool.h"

int main()
{
	floatTree *HW5 = createFloatTree();                 // створюю дерево

	insertFloatValueToTree(HW5, 28.3);                   // дадаю єлементи у дерево
	insertFloatValueToTree(HW5, 35.2);
	insertFloatValueToTree(HW5, 19.1);
	insertFloatValueToTree(HW5, 108.1);
	insertFloatValueToTree(HW5, 14.4);
	insertFloatValueToTree(HW5, 19.07);
	insertFloatValueToTree(HW5, 15.42);
	insertFloatValueToTree(HW5, 12.10);

	printf("\n");
	printTree(HW5->root);                                  // друкую єлементи дерева

	printf("\n\nNode : %.2f\n\n", findNodeWithValue(HW5, 15.42)->value);       // знахожу елемент у початковому дереві

	deleteValueFromTree(HW5, 35.2);                                            // видаляю єлементи дерева
	deleteValueFromTree(HW5, 19.07);

	printTree(HW5->root);																	                       // друкую єлементи дерева, які залишились
	printf("\n\nNode %.2f still exist\n\n", findNodeWithValue(HW5, 15.42)->value);  // знахожу елемент в новому дереві
	deleteFloatTree(HW5);                                                        // видаляю дерево
}
