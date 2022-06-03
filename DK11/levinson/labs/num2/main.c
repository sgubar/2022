#include "charList.h"
#include <string.h>

int main()
{
    char c;
    char input[21];
    int index;

    printf("\nWelcome to the linked list demo program! Do you wish to proceed (y/n)?\n");
    scanf(" %c", &c);

    if(c != 'y')
    {
        return 0;
    }

    printf("\nPlease enter an initial string of chars of length 20 or less to be stored in the list: ");
    scanf("%20s", input);

    ListPtr list = init_list(input);

    printf("\nYou can now manipulate this list, type any valid command or 'man' to get a list of available commands.\n\n");

    while(strcmp(input, "quit") != 0)
    {
        memset(input, 0, sizeof(char) * 21);
        scanf("%20s", input);
        
        if(strcmp(input, "man") == 0)
        {
            printf("\n\nAvailable commands:\n\n'append [string]' - appends characters of a given [string] to the end of current list in the provided order.\n\n'insertat [index] [string]' - inserts chars of [stirng] at [index] position in the list, shifting the rest of the list forward by the length of [string]. \n'insertat 0 [src]' is equivalent to appending dest to src, while 'insertat [dest_length] [src]' is equivalent to 'append [src]'\n\n'deleteat [index]' - delets entry at a given index, shifting the rest of the list backward by one.\n\n'duplicate [char]' - duplicates a [char] throughout the list.\n\n'print' - prints the current state of the list.\n\n'quit' - exits the program.\n\n");
        }
        else if(strcmp(input, "append") == 0)
        {
            memset(input, 0, sizeof(char) * 21);
            scanf("%20s", input);

            append_elements(list, input);
        }
        else if(strcmp(input, "insertat") == 0)
        {
            memset(input, 0, sizeof(char) * 21);
            scanf("%i", &index);
            scanf("%20s", input);

            insert_elements(list, input, index);
        }
        else if(strcmp(input, "deleteat") == 0)
        {
            memset(input, 0, sizeof(char) * 21);
            scanf("%i", &index);

            delete_nth(list, index);
        }
        else if(strcmp(input, "duplicate") == 0)
        {
            memset(input, 0, sizeof(char) * 21);
            scanf("%1s", input);

            duplicate_element(list, input);
        }
        else if(strcmp(input, "print") == 0)
        {
            print_list(list);
        }
        else if(strcmp(input, "quit") == 0)
        {
            printf("\nThanks for using linked list demo program.\n");
        }
        else
        {
            printf("\nInvalid input: %s; Use 'man' command to get a list of valid commands.\n\n", input);
        }
    }
}