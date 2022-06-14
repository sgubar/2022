#include <iostream>
#include <string.h>
using namespace std;

// 3 варіант
// Клас книги Book: назва, ім’я автора, кількість сторінок, рік видання.

class Book
{
private:
	int numberofpages, yearofwriting; // значення за замовчуванням
	const char* author, * book; // значення за замовчуванням


public:
	// модифікатор, присвоєння параметрів
	void set_numberofpages(int new_numberofpages)
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
	// Повернення значень
	const char* get_bookname()
	{
		return book;
	}
	int get_lengthofbookname()
	{
		int length = strlen(book);
		return length;
	}
	//створення нових об'єктів
	Book(int new_numberofpages, int new_yearofwriting, const char* new_authorname, const char* new_bookname) // конструктор для нових об'єктів
	{
		numberofpages = new_numberofpages;
		yearofwriting = new_yearofwriting;
		author = new_authorname;
		book = new_bookname;
		display();
	}
	// конструктор за замовчуванням
	Book()
	{
		numberofpages = 0;
		yearofwriting = 0;
		author = "...";
		book = "...";
	}

	void display() // виведення
	{
		cout << "Hello, my name is " << author << ", I am the author of `" << book << "`, which was written in " << yearofwriting << ".It was " << numberofpages << " pages.\n";
	}

	~Book() // деструктор
	{
		cout << "destroyed\n"; // отримаемо повідомлення декілька разів(залежить від кількості об'єктів зроблених через конструктор)
	}
};

int main() //  приклад роботи програми
{
	// перший спосіб задання інформації
	Book novelbook;
	novelbook.set_numberofpages(20);
	novelbook.set_yearofwriting(1908);
	novelbook.set_authorname("Mykhailo Mykhailovych Kotsyubynsky");
	novelbook.set_bookname("Intermezo");
	novelbook.display();
	cout << novelbook.get_lengthofbookname() << " - the length of the book name" << endl; // приклад роботи селектора

	// другий спосіб задання інформації
	Book adventurebook(320, 1876, "Mark Twain", "The Adventures of Tom Sawyer");
	cout << adventurebook.get_lengthofbookname() << " - the length of the book name" << endl; // приклад роботи селектора

	// приклад роботи конструктора копіювання
	Book copyadventurebook = Book(adventurebook);
	copyadventurebook.display();

	Book testbook(220, 2022, "Avramenko", "ZNO");
	cout << testbook.get_bookname() << " - the length of the book name" << endl; 

	return 0;
}
