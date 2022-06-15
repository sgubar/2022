#include <stdio.h>
#include "dk12_tool.h"

int main()
{
    FILE *flow = fopen("test.txt", "r");

    char tmpCharacter;

    Row *tmpRow = crtRow();

    while ((tmpCharacter = fgetc(flow)) != EOF)
    {
        if (tmpCharacter == '\n')
        {
            prtReverseRow(tmpRow);

            delRow(tmpRow);

            tmpRow = crtRow();
        }

        else
        {
            addCharacterToRow(tmpRow, tmpCharacter);
        }
    }

    prtReverseRow(tmpRow);

    delRow(tmpRow);

    fclose(flow);

    return 0;

}
