#include <iostream>
#include <string.h>
using namespace std;

class Text
{
	const char* txt;
	int len;

public:

	void setText(const char* new_text) // модифікатор
	{
		txt = new_text;
		len = strlen(new_text);
	}

	int getLengt() // селектор
	{
		int len = strlen(txt);
		return len;
	}

	Text(const char* text) // конструктор
	{
		len = strlen(text);
		txt = text;
	}

	Text() // конструктор за замовчуванням
	{
		txt = "DEFAULT TEXT";
		len = strlen(txt);
	}

	Text(const Text& text): // конструктор копіювання
		txt(text.txt), len(text.len)
	{
		std::cout << "Text copied!\n";
	}

	~Text() // деструктор
	{
		std::cout << "\nText deleted!";
	}

	void output() // виведення тексту
	{
		std::cout << txt << " - (" << len << ")\n";
	}
};

int main()
{
	int len;
	Text txt1; // конструктор за замовченням
	Text txt2("COPIED TEXT"); // конструктор
	Text txt3(txt2); // конструктор копіювання
	txt2.setText("REPLACED TEXT"); // модифікатор
	len = txt3.getLengt(); // селектор
	std::cout << "Get lengt copied text: " << len << "\n\n";
	txt1.output();
	txt2.output();
	txt3.output();
}