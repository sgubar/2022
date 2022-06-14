#ifndef DK12_TOOL_H
#define DK12_TOOL_H
#include <stdio.h>

typedef struct tagCharacter Character;

struct tagCharacter
{
    char value;
    Character *prev;
    Character *next;
};


Character *crtCharacter(char value);
void delCharacter(Character *element);
void prtCharacter(Character *element);


typedef struct tagRow
{
    Character *head;
  
    Character *tail;
} Row;

Row *crtRow(void);

void delRow(Row *list);

void prtReverseRow(Row *list);

int addCharacterToRow(Row *list, char value);


#endif 
