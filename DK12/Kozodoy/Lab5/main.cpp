#include <iostream>
#include <string.h>
using namespace std;

class Text
{
	const char* txt;
	int len;

public:

	void setText(const char* new_text) // �����������
	{
		txt = new_text;
		len = strlen(new_text);
	}

	int getLengt() // ��������
	{
		int len = strlen(txt);
		return len;
	}

	Text(const char* text) // �����������
	{
		len = strlen(text);
		txt = text;
	}

	Text() // ����������� �� �������������
	{
		txt = "DEFAULT TEXT";
		len = strlen(txt);
	}

	Text(const Text& text): // ����������� ���������
		txt(text.txt), len(text.len)
	{
		std::cout << "Text copied!\n";
	}

	~Text() // ����������
	{
		std::cout << "\nText deleted!";
	}

	void output() // ��������� ������
	{
		std::cout << txt << " - (" << len << ")\n";
	}
};

int main()
{
	int len;
	Text txt1; // ����������� �� �����������
	Text txt2("COPIED TEXT"); // �����������
	Text txt3(txt2); // ����������� ���������
	txt2.setText("REPLACED TEXT"); // �����������
	len = txt3.getLengt(); // ��������
	std::cout << "Get lengt copied text: " << len << "\n\n";
	txt1.output();
	txt2.output();
	txt3.output();
}