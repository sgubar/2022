#include <stdio.h>
#include "dk12_tool.h"
#include <conio.h>
//#include <clocale>

int main(int argc, const char* argv[]) {

    BinaryTree* tree = createTree();
    int result;

    unsigned numberOfValues = 0;
    printf("Кількість значень які ви хочете внести : ");
    result = scanf("%u", &numberOfValues);
    if (!result) {
        return 1;
    }

    while (numberOfValues--) {
        int value;
        printf("Введіть значення (від -32,768 до 32,767): ");
        result = scanf("%i", &value);
        if (result == 1) {
            insert(tree, value);
        }
    }

    print(tree);

    int valueToFind;
    //setlocale (LC_CTYPE, "ukr");
    printf("Яке значення ви бажаєте найти?\nВведіть значення (від -32,768 до 32,767): ");
    result = scanf("%i", &valueToFind);
    if (!result) {
        return 1;
    }

    Node* foundedNode = find(tree, valueToFind);
    if (foundedNode != NULL) {
        //setlocale (LC_CTYPE, "ukr");
        printf("Це значення в дереві за адресою: %p\n", foundedNode);
    }
    else {
        //setlocale (LC_CTYPE, "ukr");
        printf("Цього елемента не існує ¯\\_(ツ)_//¯ \n");
    }

    int valueToDelete;
    //setlocale (LC_CTYPE, "ukr");
    printf("Значення яке ви бажаєте ЗНИЩИТИ!!! \nВведіть значення (від -32,768 до 32,767): ");
    result = scanf("%i", &valueToDelete);
    if (!result) {
        return 1;
    }

    delete(tree, valueToDelete);
    print(tree);

    destroyTree(tree);
    print(tree);
   getch();
    return 0;
}
