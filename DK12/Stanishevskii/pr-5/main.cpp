#include <iostream>
#include <string.h>
using namespace std;

/* Варіант 5 */

class Text
{
private:
    const char *text;
    long int length;

public:
    void set_text(const char *new__text)
    {
        text = new__text;
        length = strlen(text);
    }

    int get_length()
    {
        return length;
    }

    const char *getText()
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
        text = "---";
        length = 0;
    }

    void display()
    {
        cout << "Введенний текст: " << text << "\n";
    }

    ~Text()
    {
        cout << "Текст було видалено\n";
    }
};

int main(void)
{
    Text Text1;
    Text1.set_text("Рандомний текст номер один");
    Text1.display();
    cout << "Довжина тексту: " << Text1.get_length() << "\n"
         << endl;
    int index = 3;
    cout << "Текст:\n"
         << Text1.getText() << "\n"
         << endl;

    Text Text2("І наприклад рандомний текст номер два");

    Text copy__Text2 = Text(Text2);
    copy__Text2.display();

    return 1;
}
