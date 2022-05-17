using namespace std;

class List
{
    struct Node;
    Node* Root = nullptr;
    Node* Current = nullptr;
public:
    void addelem(string a);
    void readfile (const char *filename);
    void reverseprint();
};
