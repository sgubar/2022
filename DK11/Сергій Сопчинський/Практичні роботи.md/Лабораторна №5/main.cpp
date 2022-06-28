#include <iostream>
#include <string.h>
using namespace std;

class Book
{
private:
	int numberofpages, yearofwriting; // значення за замовчуванням
	const char *author, *book; // значення за замовчуванням

public:
	void set_numberofpages(int new_numberofpages) // модифікатор
	{
		numberofpages = new_numberofpages;
	}
	void set_yearofwriting(int new_yearofwriting)
	{
		yearofwriting = new_yearofwriting;
	}
	void set_authorname(const char* new_authorname)
	{
		author = new_authorname;
	}
	void set_bookname(const char* new_bookname)
	{
		book = new_bookname;
	}
	
	int get_lengthofbookname() // селектор
	{
		int length = strlen(book);
		return length;
	}
	Book(int new_numberofpages, int new_yearofwriting, const char* new_authorname, const char* new_bookname) // конструктор для нових об'єктів
	{
		numberofpages = new_numberofpages;
		yearofwriting = new_yearofwriting;
		author = new_authorname;
		book = new_bookname;
		display();
	}
	Book() // конструктор за замовчуванням
	{
		numberofpages = 0;
		yearofwriting = 0;
		author = "...";
		book = "...";
	}
int main() //  приклад роботи програми	
{
	Book novelbook; // перший спосіб задання інформації
	novelbook.set_numberofpages(304);
	novelbook.set_yearofwriting(1954);
	novelbook.set_authorname("William Golding");
	novelbook.set_bookname("LORD OF THE FLIES");
	novelbook.display();
	cout << novelbook.get_lengthofbookname() << " - the length of the book name" << endl; // приклад роботи селектора
	Book adventurebook(412, 1965, "Frank Herbert", "Duna"); // другий спосіб задання інформації
	cout << adventurebook.get_lengthofbookname() << " - the length of the book name" << endl; // приклад роботи селектора
	Book copyadventurebook = Book(adventurebook); // приклад роботи конструктора копіювання
	copyadventurebook.display();
	return 0;
}
