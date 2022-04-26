#include <stdlib.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>
#include "nod.h"

int main(int argc, char *argv[])
{
    if(argc == 1) {
        printf("Please pass text size as an argument.\n");
        exit(EXIT_FAILURE);
    }   
    char text[atoi(argv[1])];
    Node *head = NULL;

    printPrompt();
    fgets(text, atoi(argv[1])+1, stdin);

    for(int i=0; i < atoi(argv[1]); i++) {

       if(openingBracket(&text[i])) {   //STACK
           if(head == NULL) {
                head = createNode(NULL, &text[i]);   
            } else {
                head->next = createNode(head, &text[i]);                        
                head = head->next;
                }            
        }  
        else if(closingBracket(&text[i])) {
           if(head == NULL) {
               notBalanced();
            }
            else if(correctClosingBracket(head, &text[i])) {
               head = head->prev;            
            } else {
                free(head);
                notBalanced();
                }

        } else; //skip
    }
    if(head == NULL)
        balanced();
     else 
        notBalanced();   
}