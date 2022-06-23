#include <iostream>
#include <string.h>
using namespace std;

// Варіант 5

class Text
{
protected:
    const char *text;
    long length;

public:
    void set_text(const char *new__text)
    {
        text = new__text;
        length = strlen(text);
    }

    int get_text_length()
    {
        return length;
    }

    const char *get_all_text()
    {
        return text;
    }

    Text(const char *new__text)
    {
        text = new__text;
        display();
    }

    Text()
    {
        text = "";
        length = 0;
    }

    void display()
    {
        cout << "\nText:\n"
             << text << "\n";
    }

    ~Text()
    {
        cout << "Text destroyed\n";
    }
};

int main(void)
{
    Text Text_one;
    Text_one.set_text("Just text one");
    Text_one.display();
    cout << "Length: " << Text_one.get_text_length() << endl;
    int index = 3;
    cout << "\nGet all text:\n"
         << Text_one.get_all_text() << "\n"
         << endl;

    Text Text_two("Just text two");

    Text copy__Text_two = Text(Text_two);
    copy__Text_two.display();

    return 1;
}
