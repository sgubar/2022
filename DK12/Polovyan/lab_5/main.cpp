#include <iostream>
#include <string.h>
using namespace std;

class Book
{
private:
	int numberOfPages, yearOfPubclishing; // значення за замовчуванням
	const char *authorName, *bookName;	  // значення за замовчуванням

public:
	void set_numberOfPages(int new__numberOfPages) // функція для присвоєння параметрів - модифікатор
	{
		numberOfPages = new__numberOfPages;
	}
	void set_yearOfPubclishing(int new__yearOfPubclishing)
	{
		yearOfPubclishing = new__yearOfPubclishing;
	}
	void set_authorName(const char *new__authorName)
	{
		authorName = new__authorName;
	}
	void set_bookName(const char *new__bookName)
	{
		bookName = new__bookName;
	}
	//====================================================================================================================================================================//
	int get_lengthOfAuthorName() // функція для повернння значень - селектор
	{
		int length = strlen(authorName);
		return length;
	}
	//====================================================================================================================================================================//
	Book(int new__numberOfPages, int new__yearOfPubclishing, const char *new__authorName, const char *new__bookName) // конструктор для створення нових об'єктів
	{
		numberOfPages = new__numberOfPages;
		yearOfPubclishing = new__yearOfPubclishing;
		authorName = new__authorName;
		bookName = new__bookName;
		display();
	}

	Book() // конструктор за замовчуванням
	{
		numberOfPages = 0;
		yearOfPubclishing = 0;
		authorName = "----------";
		bookName = "----------";
	}
	//====================================================================================================================================================================//
	void display() // функція для виведення
	{
		cout << "\nMy name is " << authorName << ", I wrote the `" << bookName << "` book. It was written " << yearOfPubclishing << " and has " << numberOfPages << " pages.\n\n";
	}
	//====================================================================================================================================================================//
	~Book() // деструктор
	{
		cout << "program destroyed\n"; // отримаємо повідомлення деілька раз в залежності від того, скільки в нас об'єктів зроблено саме через КОНСТРУКТОР (а не функцію set)
	}
};

int main()
{
	//================================================================================//  приклад роботи програми

	Book psychologicalBook; // не обов'язково вказувати усі значення, у випадку пропуску - вкажуться значення за замовчуванням (для цього декілька значень закоментовані)
	psychologicalBook.set_numberOfPages(756);
	psychologicalBook.set_yearOfPubclishing(1997);
	// psychologicalBook.set_authorName("Daniel Goleman");
	// psychologicalBook.set_bookName("Emotional Intelligence");
	psychologicalBook.display();
	cout << psychologicalBook.get_lengthOfAuthorName() << " - the length of the author name\n\n" << endl; // приклад роботи селектора

	Book businessBook(222, 2004, "John Brooks", "Business Adventures");

	Book copyOfBusinessBook = Book(businessBook); // приклад роботи конструктора копіювання, який при компіляції програми був створений автоматично
	copyOfBusinessBook.display();

	//================================================================================//
	return 0;
}
