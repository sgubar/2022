#include <stdio.h>
#include "dk11_tool.h"

int main()
{
	intTree *LAB3 = createIntTree(); 

	insertIntValueToTree(LAB3, 20); 
	insertIntValueToTree(LAB3, 5);
	insertIntValueToTree(LAB3, 11);
	insertIntValueToTree(LAB3, 100);
	insertIntValueToTree(LAB3, 6);
	insertIntValueToTree(LAB3, 10);
	insertIntValueToTree(LAB3, 7);
	insertIntValueToTree(LAB3, 4);

	printf("\n");
	printTree(LAB3->root); 

	printf("\n\nNode : %d\n\n", findNodeWithValue(LAB3, 5)->value); 

	deleteValueFromTree(LAB3, 100); 
	deleteValueFromTree(LAB3, 10);

	printTree(LAB3->root);																	  
	printf("\n\nNode %d still exist\n\n", findNodeWithValue(LAB3, 5)->value); 
	deleteIntTree(LAB3); 
}
