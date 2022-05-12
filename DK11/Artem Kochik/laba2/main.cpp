#include <iostream>
#include <string.h>

using namespace std;
class List
{
    struct Node
    {
        char data[255];
        Node * next = nullptr;
    };
    Node* Root = nullptr;
    Node* Current = nullptr;
public:
    void addelem(char* a)
    {
        Node* node = new Node();
        strcpy(node->data, a);
        if (Root == NULL)
        {
            Current = Root = node;
            return;
        }
        Node* current;
        for (current = Root; current->next != nullptr; current = current->next);
        current->next = node;
    }
    void reverseprint()
    {
        Node* current;
        for (current = Root; current != nullptr; current = current->next)
        {
            char str1[255];
            strcpy(str1, current->data);
            for(int i = strlen(str1); i>=0;i--){
                cout<<str1[i];
            }
        }
    }
    void readfromfile (const char *filename)
  {
    FILE *fp = fopen (filename, "r");
    char str[255];
    if (fp != NULL)
      {
	while (!feof (fp))
	  {
	    fgets (str, 127, fp);
	    addelem (str);
	  }
	fclose (fp);
      }
    else
      {
	cout << "Could not open '" << filename << "'." << endl << endl << endl;
	exit (0);
      }
  }
    
};

int main()
{
    List list;
    list.readfromfile("textfile.txt");
    cout<<"Reverse print: "<<endl<<endl;
    list.reverseprint();
    return 0;
}
