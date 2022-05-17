#include <iostream>
#include <string.h>
#include <fstream>

#include "dk11_tool.h"

int main()
{
    List list;
    list.readfile("textfile.txt");
    cout<<"Reverse print: "<<endl<<endl;
    list.reverseprint();
    return 0;
}
