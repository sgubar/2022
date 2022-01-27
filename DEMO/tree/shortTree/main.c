//
//  main.c
//  demoTree2
//
//  Created by Slava Gubar on 4/25/17.
//  Copyright © 2017 Slava Gubar. All rights reserved.
//

#include <stdio.h>
#include "tree.h"

int main(int argc, const char * argv[]) {
	ShortTree *tree = createShortTree();
	insertShortValueToTree(tree, 53);
	insertShortValueToTree(tree, 30);
	insertShortValueToTree(tree, 14);
	insertShortValueToTree(tree, 9);
	insertShortValueToTree(tree, 23);
	insertShortValueToTree(tree, 39);
	insertShortValueToTree(tree, 35);
	insertShortValueToTree(tree, 43);
	printTree(tree);
	deleteNodeWithValue(tree, 30);
	printTree(tree);

	destroyShortTree(tree);
	
	// insert code here...
	printf("Hello, World!\n");
	return 0;
}
