#include <stdio.h>
#include "inttree.h"

int main(int argc, const char * argv[]){

	IntTree *inttree = createIntTree();
	insertIntValueToTree(inttree,80);
	insertIntValueToTree(inttree,33);
	insertIntValueToTree(inttree,86);
	insertIntValueToTree(inttree,12);
	insertIntValueToTree(inttree,25);
	insertIntValueToTree(inttree,8);
	insertIntValueToTree(inttree,26);
	insertIntValueToTree(inttree,53);
	printTree(inttree);

	deleteNodeWithValue(inttree,8);
	printTree(inttree);

	deleteIntTree(inttree);
}
