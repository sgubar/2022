#include<stdio.h>
#include<string.h>
#include"dk_tool.h"

int main(){
	char sentense[200];
	
	printf("Підрахунок слів у реченні\n\nВВедідь речення: ");
	gets(sentense);
	puts("\n\n\nВвід: ");
	puts(sentense);
	
	printf("\n\n---------------------------------------\n\nкількість слів: %d", how_many_words(sentense));
	
	getchar();
	return 0;
}
