#include <iostream>
#include <string.h>
#include <fstream>

#include "dk11_tool.h"

using namespace std;

    struct List::Node
    {
        string data;
        Node * next = nullptr;
    };
    void List::addelem(string a)
    {
        Node* node = new Node();
        node->data=a;
        if (Root == NULL)
        {
            Current = Root = node;
        }
        else{
        Node* current;
        for (current = Root; current->next != nullptr; current = current->next);
        current->next = node;
        }
    }
    void List::readfile (const char *filename)
    {
        string str;
        ifstream file(filename);
        if(file.is_open()){
            while(getline(file, str)){
                addelem(str);
            }
            file.close();
        }
        else{
            cout << "Could not open '" << filename << "'." << endl << endl << endl;
 	        exit (0);
        }
  }
    void List::reverseprint()
    {
        Node* current;
        for (current = Root; current != nullptr; current = current->next)
        {
            for(int i = current->data.length(); i>=0;i--){
                cout<<current->data[i];
            }
            cout<<endl;
        }
    }
